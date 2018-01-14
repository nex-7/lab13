[![Build Status](https://travis-ci.org/nex-7/lab13.svg?branch=master)](https://travis-ci.org/nex-7/lab13)

### Laboratory work XIII

Написать программы на **C++** для сериализации и десериализации структуры `Person`.

Структура `Person` определяется следующим образом:

```cpp
struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};
```

Пример сериализации структуры `Person` 
```ShellSession
$ ./pack /path/to/file
Enter data to fields of the Person structure.
First name:
Petr↵
Last name:
Ivanov↵
Email:
ivanov_petr_97@gmail.com
Age(optional):
20↵
Phone (optional):
↵
```

Пример десериализации структуры `Person` 
```ShellSession
$ ./unpack /path/to/file
[Person]
Fisrt name: Petr
Last name:  Ivanov
Email:      ivanov_petr_97@gmail.com
Age:        20
```

### Проект
Создаем файл в формате `xml` и заполняем его.
```ShellSession
$ ./pack test.xml
Enter data to fields of the Person structure.
First name:
$ Ivan

Last name:
$ Ivanov

Email:
$ IvanIvanov@bmstu.ru

Age (optional):
$ 45

Phone (optional):
$ 8 (999) 999-99-99
```

Проверяем наличие `test.xml`.
```ShellSession
$ cat test.xml

<?xml version="1.0"?>
<person>
	<first_name>Ivan</first_name>
	<last_name>Ivanov</last_name>
	<email>IvanIvanov@bmstu.ru</email>
	<age>45</age>
	<phone>8 (999) 999-99-99</phone>
</person>
```

Теперь распаковываем файл.
```ShellSession
$ ./unpack test.xml
[Person]
First name: Ivan
Last name: Ivanov
Email: IvanIvanov@bmstu.ru
Age (optional): 45
Phone (optional): 8 (999) 999-99-99
```

### Результат проверки валидности через XML Lint

```ShellSession
$ xmllint test.xml

<?xml version="1.0"?>
<person>
	<first_name>Ivan</first_name>
	<last_name>Ivanov</last_name>
	<email>IvanIvanov@bmstu.ru</email>
	<age>45</age>
	<phone>8 (999) 999-99-99</phone>
</person>

```

### Ссылки
Библиотеки для работы с различными форматами данных:
- [json](https://github.com/nlohmann/json)
- [yaml](https://github.com/jbeder/yaml-cpp)
- [xml](https://github.com/zeux/pugixml)
- [protobuf](https://github.com/google/protobuf)

