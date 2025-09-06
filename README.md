# 📘 Объектно-ориентированное программирование (ООП) / Object-Oriented Programming (OOP)

## 📖 Описание курса / Course Description
Курс посвящён основам и практическому применению **объектно-ориентированного подхода** в программировании на C++.  
Рассматриваются ключевые принципы: **инкапсуляция, наследование, полиморфизм, перегрузка операторов, работа с динамической памятью, абстрактные классы**.  

Практика включает 6 лабораторных работ, каждая из которых постепенно усложняет проект и добавляет новые аспекты объектно-ориентированного проектирования.

The course focuses on the basics and practical application of the object-oriented approach in C++ programming.  
The key principles are considered: **encapsulation, inheritance, polymorphism, operator overloading, working with dynamic memory, abstract classes**.  

The practice includes 6 laboratory works, each of which gradually complicates the project and adds new aspects of object-oriented design.

---

## 🔹 Лабораторные работы / Labs

### 1️⃣ Лабораторная 1 — Класс `Rectangle` / Class `Rectangle`

**РУС:**
**Задача:** реализовать класс для работы с прямоугольниками и вспомогательный класс координат.  

**Функционал:**
- ввод и вывод данных (`Input`, `Output`);
- вычисление площади и периметра;
- нахождение радиуса описанной окружности;
- проверка, является ли прямоугольник квадратом;
- масштабирование (умножение сторон на число);
- сравнение на равенство и подобие;
- вычисление центра описанной окружности;
- проверка пересечения двух прямоугольников;
- построение прямоугольника пересечения.

**Ключевые классы:**
- `Coordinates` — хранение координат точки;
- `Rectangle` — работа с геометрическими свойствами прямоугольника.

**ENG:**
**Task:** implement a class to work with rectangles and a helper class for coordinates.  

**Functionality:**
- input and output of data (`Input`, `Output`);
- calculate area and perimeter;
- find the radius of the circumscribed circle;
- check if the rectangle is a square;
- scaling (multiply sides by a number);
- compare for equality and similarity;
- calculate the center of the circumscribed circle;
- check the intersection of two rectangles;
- construct the intersection rectangle.

**Key classes:**
- `Coordinates` — stores point coordinates;
- `Rectangle` — works with geometric properties of the rectangle.

---

### 2️⃣ Лабораторная 2 — Класс `Array` / Class `Array`

**РУС:**
**Задача:** реализовать класс для работы с динамическим массивом и перегрузкой операторов.  

**Функционал:**
- создание массива (конструкторы, копирование, деструктор);
- ввод и вывод элементов (`Scan`, `Print`, перегрузка `>>` и `<<`);
- доступ к элементам по индексу (`operator[]`);
- поиск элемента по значению (`FindKey`);
- добавление элементов:
  - в конец массива (`+= key`, `+ key`);
  - объединение массивов (`+= Array`, `+ Array`);
- удаление элементов:
  - по значению (`-= key`, `- key`);
  - по позиции (`DelPosEq`, `DelPosNew`);
- сравнение массивов (`==`, `!=`);
- поиск максимального и минимального элемента (`Max`, `Min`);
- сортировка массива (`Sorting`);
- генерация случайного массива (`Randomizer`).

**Особенности:**
- реализованы все основные операции с массивами через перегрузку операторов;
- поддерживается копирование и присваивание массивов;
- проверка корректности индексов.

**ENG:**
**Task:** implement a class to work with a dynamic array with operator overloading.  

**Functionality:**
- create an array (constructors, copy, destructor);
- input and output (`Scan`, `Print`, overload `>>` and `<<`);
- access elements by index (`operator[]`);
- find element by value (`FindKey`);
- add elements:
  - to the end of the array (`+= key`, `+ key`);
  - merge arrays (`+= Array`, `+ Array`);
- delete elements:
  - by value (`-= key`, `- key`);
  - by position (`DelPosEq`, `DelPosNew`);
- compare arrays (`==`, `!=`);
- find maximum and minimum (`Max`, `Min`);
- sort the array (`Sorting`);
- generate random arrays (`Randomizer`).

**Features:**
- all main operations implemented via operator overloading;
- supports copying and assignment;
- index validation.

---

### 3️⃣ Лабораторная 3 — Комплексные числа / Complex Numbers

**РУС:**
**Задача:** обобщить класс динамического массива с помощью шаблонов, чтобы он работал с любыми типами данных.  

**Функционал:** аналогично ЛР2, но для шаблонного типа `T`.

**Особенности:**
- один шаблонный класс работает с `int`, `float`, `char` и другими типами;
- протестировано с разными типами в `main`: `Array<int>`, `Array<float>`, `Array<char>`;
- показана универсальность подхода и повторное использование кода.

**ENG:**
**Task:** generalize the dynamic array class using templates to work with any data type.  

**Functionality:** same as Lab 2, but for template type `T`.

**Features:**
- one template class works with `int`, `float`, `char`, and other types;
- tested with different types in `main`: `Array<int>`, `Array<float>`, `Array<char>`;
- demonstrates code reuse and versatility.

---

### 4️⃣ Лабораторная 4 — Класс `BoolVector` / Class `BoolVector`

**РУС:**
**Задача:** реализовать класс для работы с битовыми векторами.  

**Функционал:**
- разные конструкторы;
- ввод и вывод (`Scan`, `Print`, перегрузка `>>` и `<<`);
- операции сравнения (`==`, `!=`, `<`, `>`);
- побитовые операции (`&`, `|`, `^`, `~`);
- побитовые сдвиги (`<<`, `>>`);
- доступ к отдельному биту (`operator[]`);
- работа с весом и пакетные операции.

**Особенности:**
- хранение битов в `unsigned char`;
- поддержка операций на векторах разной длины;
- проверка побитовых операций и сдвигов.

**ENG:**
**Task:** implement a class to work with bit vectors.  

**Functionality:**
- various constructors;
- input/output (`Scan`, `Print`, overload `>>` and `<<`);
- comparison operations (`==`, `!=`, `<`, `>`);
- bitwise operations (`&`, `|`, `^`, `~`);
- bit shifts (`<<`, `>>`);
- access individual bit (`operator[]`);
- weight calculation and batch operations.

**Features:**
- bits stored in `unsigned char`;
- support operations on vectors of different lengths;
- tested bitwise operations and shifts.

---

### 5️⃣ Лабораторная 5 — Класс `BoolMatrix` / Class `BoolMatrix`

**РУС:**
**Задача:** реализовать класс для работы с булевыми матрицами на основе `BoolVector`.  

**Функционал:**
- конструкторы;
- ввод и вывод (`Scan`, `Print`, перегрузка `>>` и `<<`);
- сравнение (`==`, `!=`);
- доступ к строке (`operator[]`);
- побитовые и логические операции;
- сдвиги строк и пакетные операции.

**Особенности:**
- каждая строка — `BoolVector`;
- компактность и удобство работы;
- проверка всех операций и сдвигов.

**ENG:**
**Task:** implement a class to work with boolean matrices based on `BoolVector`.  

**Functionality:**
- constructors;
- input/output (`Scan`, `Print`, overload `>>` and `<<`);
- comparison (`==`, `!=`);
- access row (`operator[]`);
- bitwise and logical operations;
- row shifts and batch operations.

**Features:**
- each row stored as `BoolVector`;
- compact and convenient;
- all operations and shifts tested.

---

### 6️⃣ Лабораторная 6 — Полиморфизм и источники данных / Polymorphism and Data Sources

**РУС:**
**Задача:** реализовать иерархию классов для получения числовых данных из различных источников и их анализа.  

**Классы:**
- `SBase`, `SKbrd`, `SFile`, `SQueue`, `Freq`, `Diap`.

**Функционал:**
- единый интерфейс (`SBase`);
- наследование и переопределение `Get()`;
- подсчёт статистики с `std::map`;
- перегрузка `operator<<` для вывода;
- демонстрация полиморфизма и расширяемости.

**Примеры использования:**
- ввод с клавиатуры (`SKbrd`);
- обработка файла (`SFile`);
- псевдослучайная последовательность (`SQueue`);
- вывод статистики (`Freq`, `Diap`).

**ENG:**
**Task:** implement a class hierarchy to obtain numeric data from various sources and analyze it.  

**Classes:**
- `SBase`, `SKbrd`, `SFile`, `SQueue`, `Freq`, `Diap`.

**Functionality:**
- unified interface (`SBase`);
- inheritance and override of `Get()`;
- statistics using `std::map`;
- overload `operator<<` for output;
- demonstrates polymorphism and extensibility.

**Usage examples:**
- input from keyboard (`SKbrd`);
- file processing (`SFile`);
- pseudo-random sequence (`SQueue`);
- display statistics (`Freq`, `Diap`).

---

## 🛠️ Технологии / Technologies
- C++  
- ООП: классы, наследование, полиморфизм  
- Перегрузка операторов  
- Работа с динамической памятью  
- STL (`<map>`, `<iostream>`, `<fstream>`)

---

## 📂 Структура репозитория / Repository Structure

/lab1 → Rectangle  
/lab2 → Array  
/lab3 → Complex  
/lab4 → BoolVector  
/lab5 → BoolMatrix  
/lab6 → Polymorphism (Freq & Diap)

---

## 🎯 Цель курса / Purpose of the Course
Освоить объектно-ориентированное программирование в C++, научиться проектировать классы, применять полиморфизм, перегрузку операторов и шаблоны для создания универсальных структур данных.  

Learn object-oriented programming in C++, design classes, use polymorphism, operator overloading, and templates to create versatile data structures.

---
