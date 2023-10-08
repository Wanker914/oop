# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru

import json
from functools import total_ordering
from itertools import count
from typing import Sequence


@total_ordering
class Date:
    DAYS_ON_MONTH = {
        0: 31,
        1: 28,
        2: 31,
        3: 30,
        4: 31,
        5: 30,
        6: 31,
        7: 31,
        8: 30,
        9: 31,
        10: 30,
        11: 31,
    }
    DAYS_ON_YEAR = 365

    def __init__(self, *, year: int, month: int, day: int) -> None:
        self._year, self._month, self._day = year, (month - 1) % 12, day
        self._validate_all_attrs()

    def __str__(self) -> str:
        return f'{self._year:04d}-{(self._month + 1) % 12:02d}-{self._day:02d}'

    def __repr__(self) -> str:
        return f'"{str(self)}"'

    def __sub__(self, other_date: 'Date') -> int:
        date1, date2 = sorted([self, other_date])
        date3 = Date(year=date2._year, month=1, day=1)
        total_days = date2.days_to_start_year + date1.days_to_end_year
        for year in range(date1._year, date2._year):
            date3.sub_years(1)
            total_days += self.DAYS_ON_YEAR + date3.is_leap
        return total_days

    def __eq__(self, other_date: 'Date') -> bool:
        return self.to_tuple() == other_date.to_tuple()

    def __le__(self, other_date: 'Date') -> bool:
        return self.to_tuple() <= other_date.to_tuple()

    @property
    def is_leap(self) -> bool:
        year = self._year
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

    @property
    def days_to_start_year(self) -> int:
        days = self._day
        for i in range(self._month - 1, -1, -1):
            days += self.DAYS_ON_MONTH[i] + (self.is_leap and self._month == 1)
        return days

    @property
    def days_to_end_year(self) -> int:
        days = self.DAYS_ON_YEAR + self.is_leap
        return days - self.days_to_start_year

    def _validate_year(self):
        if self._year <= 0:
            raise TypeError('Год должен принимать значения большие ноля')

    def _validate_month(self):
        if not 0 <= self._month <= 11:
            raise TypeError('Месяц должен принимать значения от 1 до 12')

    def _validate_day(self):
        if not 1 <= self._day <= self.DAYS_ON_MONTH[self._month] + (self.is_leap and self._month == 2):
            raise TypeError('Указано неверное количество дней в введеном месяце')

    def _validate_all_attrs(self):
        self._validate_year()
        self._validate_month()
        self._validate_day()

    @classmethod
    def from_dict(cls, date_dct: dict[str, int]) -> 'Date':
        return Date(**date_dct)

    @classmethod
    def from_string(cls, date_str: str) -> 'Date':
        year, month, day = map(int, date_str.split('-'))
        return Date(year=year, month=month, day=day)

    @classmethod
    def load(cls, filename: str) -> 'Date':
        with open(filename, 'rb') as file:
            date_dct = json.load(file)
            return Date(year=date_dct['year'], month=date_dct['month'], day=date_dct['day'])

    def save(self, filename: str) -> None:
        with open(filename, 'w', encoding='utf8') as file:
            file.write(json.dumps(self.to_dict()))

    def to_tuple(self) -> Sequence[int]:
        return self._year, self._month, self._day

    def to_dict(self) -> dict[str, int]:
        date_dct = {
            'year': self._year,
            'month': (self._month + 1) % 12,
            'day': self._day,
        }
        return date_dct

    def add_years(self, years: int) -> None:
        self._year += years

    def add_months(self, months: int) -> None:
        self._month = (self._month + months) % 12
        self._year += (self._month + months) // 12

    def add_days(self, days: int) -> None:
        total_days = self._day + days
        coef = -1 if days < 0 else 1
        total_months = 0
        for i in count(self._month, coef):
            days_in_current_month = (self.DAYS_ON_MONTH[i * coef % 12] + (self.is_leap and i % 12 == 1)) * coef
            if total_days * coef <= days_in_current_month * coef and total_days > 0:
                break

            total_days -= days_in_current_month
            total_months += coef
            if total_months % 12 == 0:
                self._year += coef

        self._month = (self._month + total_months) % 12
        self._day = total_days
        self._validate_year()

    def sub_years(self, years: int) -> None:
        self.add_years(-years)

    def sub_months(self, months: int) -> None:
        self.add_months(-months)

    def sub_days(self, days: int) -> None:
        self.add_days(-days)
