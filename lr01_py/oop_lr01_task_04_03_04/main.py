# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru


from date import Date

if __name__ == "__main__":
    date1 = Date(year=2023, month=3, day=13)
    date2 = Date(year=917, month=10, day=1)
    assert str(date1) == '2023-03-13'
    assert str(date2) == '0917-10-01'
    assert date1 == date1
    assert date1 != date2
    assert date1 <= date1
    assert date2 >= date2
    assert date2 < date1
    assert date1 > date2

    date1.add_years(5)
    date1.sub_years(5)
    assert date1 == Date(year=2023, month=3, day=13)

    date1.add_months(37)
    date1.sub_months(37)
    assert date1 == Date(year=2023, month=3, day=13)

    date1.add_days(324534)
    date1.sub_days(324534)
    assert date1 == Date(year=2023, month=3, day=13)

    delta1 = date1 - date2
    delta2 = date2 - date1
    assert delta1 == delta2 == 404121

    date2.add_days(delta1)
    assert date1 == date2

    date1.save('date.json')
    date3 = Date.load('date.json')
    assert date1 == date3
