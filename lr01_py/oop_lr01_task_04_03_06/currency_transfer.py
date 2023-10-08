# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru

from money_transfer import MoneyTransfer


class CurrencyTransfer(MoneyTransfer):
    def __init__(self, *, amount: float, from_: int, to: int, currency: str) -> None:
        self._from, self._to, self._currency = from_, to, currency
        super().__init__(self.currency_convert(amount))

    def __str__(self) -> str:
        return f'{self.NAME} на сумму {self.amount} {self.currency}'

    @property
    def currency(self) -> str:
        return self._currency

    def currency_convert(self, amount: float) -> float:
        print(f'Конвертируем {amount} руб. в {self.currency}')
        return amount

    def confirm(self) -> None:
        if self.status != 'не подтвержден':
            raise TypeError('Подтвердить можно только не подтверждений платеж')

        self._status = 'подтвержден'
        print(f'Подтвержден {self} со счета (№{self._from}) на счет (№{self._to})')

    def perform(self) -> None:
        if self.status != 'подтвержден':
            raise TypeError('Выполнить можно только подведенный перевод')

        self._status = 'выполнен'
        print(f'Выполнен {self} со счета (№{self._from}) на счет (№{self._to})')
