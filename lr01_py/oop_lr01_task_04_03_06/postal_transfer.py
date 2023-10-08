# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru

from money_transfer import MoneyTransfer


class PostalTransfer(MoneyTransfer):
    NAME = 'почтовый перевод'

    def __init__(self, *, amount: float, from_: int, to: int) -> None:
        self._from, self._to = from_, to
        super().__init__(amount)

    def confirm(self) -> None:
        if self.status != 'не подтвержден':
            raise TypeError('Подтвердить можно только не подтверждений платеж')

        self._status = 'подтвержден'
        print(f'Подтвержден {self} c индекса {self._from} на индекс {self._to}')

    def send(self) -> None:
        if self.status != 'подтвержден':
            raise TypeError('Отправить можно только подтверждений платеж')

        self._status = 'в пути'
        print(f'Отправлен {self} c индекса {self._from} на индекс {self._to}')

    def perform(self) -> None:
        if self.status != 'в пути':
            raise TypeError('Выполнить можно только отправленный платеж')

        self._status = 'выполнен'
        print(f'Выполнен {self}  c индекса {self._from} на индекс {self._to}')
