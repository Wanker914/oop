# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru

from money_transfer import MoneyTransfer


class BankTransfer(MoneyTransfer):
    NAME = 'банковский перевод'

    def __init__(self, *, amount: float, from_: int, to: int) -> None:
        self._from, self._to = from_, to
        super().__init__(amount)

    @classmethod
    def get_hidden_card_number(cls, card_number: int) -> str:
        return '**** ' * 3  + str(card_number)[-4:]

    @property
    def from_(self) -> str:
        return self.get_hidden_card_number(self._from)

    @property
    def to(self) -> str:
        return self.get_hidden_card_number(self._to)

    def confirm(self) -> None:
        if self.status != 'не подтвержден':
            raise TypeError('Подтвердить можно только не подтверждений платеж')

        self._status = 'подтвержден'
        print(f'Подтвержден {self} с карты ({self.from_}) на карту ({self.to})')

    def perform(self) -> None:
        if self.status != 'подтвержден':
            raise TypeError('Выполнить можно только подведенный перевод')

        self._status = 'выполнен'
        print(f'Выполнен {self} с карты ({self.from_}) на карту ({self.to})')
