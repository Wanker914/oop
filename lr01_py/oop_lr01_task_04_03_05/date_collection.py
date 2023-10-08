# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru


import json
from typing import Sequence

from lr01_py.oop_lr01_task_04_03_04.date import Date


class DateCollection:
    def __init__(self, date_list: Sequence[Date] | None = None) -> None:
        self._data = date_list[::] or []

    def __str__(self) -> str:
        return str(self._data)

    def __getitem__(self, index: int):
        return self._data[index]

    def __eq__(self, other: 'DateCollection') -> bool:
        return self._data == other._data

    def __ne__(self, other: 'DateCollection') -> bool:
        return not self == other

    def add(self, date: Date) -> None:
        self._data.append(date)

    def remove(self, index: int) -> None:
        del self._data[index]

    def save(self, filename: str) -> None:
        data_dct = []
        for date in self._data:
            data_dct.append(date.to_dict())
        with open(filename, 'w', encoding='utf8') as file:
            file.write(json.dumps(data_dct))

    @classmethod
    def load(cls, filename: str) -> 'DateCollection':
        with open(filename, 'rb') as file:
            data_dct = [Date.from_dict(date_dct) for date_dct in json.load(file)]
            return DateCollection(date_list=data_dct)
