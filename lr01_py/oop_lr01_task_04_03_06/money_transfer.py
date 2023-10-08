# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru

class MoneyTransfer:
    NAME = 'денежный перевод'

    def __init__(self, amount: float) -> None:
        self._amount = amount
        self._status = 'не подтвержден'

    def __str__(self) -> str:
        return f'{self.NAME} на сумму {self.amount}'

    @property
    def status(self) -> str:
        return self._status

    @property
    def amount(self) -> float:
        return self._amount

    def perform(self) -> None:
        raise NotImplementedError
