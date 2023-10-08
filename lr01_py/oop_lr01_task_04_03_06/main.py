# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru


from currency_transfer import CurrencyTransfer
from postal_transfer import PostalTransfer
from bank_transfer import BankTransfer

if __name__ == "__main__":
    currency_transfer = CurrencyTransfer(amount=1000, from_=123, to=456, currency='USD')
    currency_transfer.confirm()
    currency_transfer.perform()
    print('-------')

    postal_transfer = PostalTransfer(amount=1000, from_=123_456, to=987_654)
    postal_transfer.confirm()
    postal_transfer.send()
    postal_transfer.perform()
    print('-------')

    bank_transfer = BankTransfer(amount=1000, from_=1234_5678_9012_3456, to=1987_6543_2109_8765)
    bank_transfer.confirm()
    bank_transfer.perform()

# Конвертируем 1000 руб. в USD
# Подтвержден денежный перевод на сумму 1000 USD со счета (№123) на счет (№456)
# Выполнен денежный перевод на сумму 1000 USD со счета (№123) на счет (№456)
# -------
# Подтвержден почтовый перевод на сумму 1000 c индекса 123456 на индекс 987654
# Отправлен почтовый перевод на сумму 1000 c индекса 123456 на индекс 987654
# Выполнен почтовый перевод на сумму 1000  c индекса 123456 на индекс 987654
# -------
# Подтвержден банковский перевод на сумму 1000 с карты (**** **** **** 3456) на карту (**** **** **** 8765)
# Выполнен банковский перевод на сумму 1000 с карты (**** **** **** 3456) на карту (**** **** **** 8765)
