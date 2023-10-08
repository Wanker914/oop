# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 9
#
# Выполнил: Кобыш В.Д.
# Группа: ПИН-б-о-22-1
# E-mail: kobysh_vlad@mail.ru


from date_collection import DateCollection, Date

if __name__ == "__main__":
    date_list = [
        Date(year=2023, month=3, day=13),
        Date(year=2022, month=3, day=13),
        Date(year=2021, month=3, day=13),
        Date(year=2020, month=3, day=13),
        Date(year=2019, month=3, day=13),
    ]
    date_collection = DateCollection(date_list)
    assert str(date_collection) == '["2023-03-13", "2022-03-13", "2021-03-13", "2020-03-13", "2019-03-13"]'
    assert date_collection[3] == Date(year=2020, month=3, day=13)

    date_collection.add(Date(year=2018, month=3, day=13))
    date_list.append(Date(year=2018, month=3, day=13))
    assert date_collection == DateCollection(date_list)

    date_collection.remove(3)
    del date_list[3]
    assert date_collection == DateCollection(date_list)

    date_collection.save('date_collection.json')
    date_collection_from_json = DateCollection.load('date_collection.json')
    assert date_collection == date_collection_from_json
