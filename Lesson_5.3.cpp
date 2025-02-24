//
//  main.cpp
//  Lesson_5.3
//
//  Created by Aleksey on 21.02.2025.
//

/*1. Опишите структуру Avto (номер, марка, объем двигателя, цвет автомобиля).
 Создайте массив из 5 элементов типа Avto. Заполните массив данными, считав их с консоли.
 Информация о каждом автомобиле вводится с новой строки,
 а элементы разделяются одним или несколькими пробелами.
 В номере автомобиля пробелы отсутствуют.
 Затем вводится цвет автомобиля.
 Вывести все автомобили данного цвета (номер и марка).
 Найдите среди них автомобиль с максимальным объемом двигателя.
 Информация о каждом выбранном автомобиле выводится с новой строки,
 поля отделяются одним пробелом.
 Затем с новой строки выводится слово
 "The best: " и полные данные об автомобиле с максимальным объемом двигателя.
 Объем двигателя выводится с одним знаком после десятичной точки.
 Если автомобилей данного цвета нет, то выводится "Error".
 Sample Input:
 C060MK14 BMW 4.4 GREY
 1234AB7BY VOLVO 2.0 GREY
 AA9265AK TOYOTA 1.8 RED
 KZ389BK VOLKSWAGEN 1.4 SILVER
 5678ABBY MERSEDES 6.0 GREY
 GREY
 Sample Output:
 C060MK14 BMW
 1234AB7BY VOLVO
 5678ABBY MERSEDES
 The best: 5678ABBY MERSEDES 6.0 GREY
 */
/*
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct Avto {
    char nomer[10];
    char mark[10];
    double engine;
    char color[10];
};
int main() {
    const int N = 5;
    Avto arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i].nomer >> arr[i].mark >> arr[i].engine >> arr[i].color;
    }
    char color[10];
    cin >> color;
    int imax = 0;
    int k = 0;
    for (int i = 0; i < N; i++) {
        if(strcmp(color, arr[i].color) == 0) {
            cout << arr[i].nomer << " " << arr[i].mark <<endl;
            if(arr[imax].engine < arr[i].engine)
                imax = i;
            k++;
        }
    }
    if(k == 0)
        cout << "Error" << endl;
    else
        cout << "The best: " << arr[imax].nomer << " " << arr[imax].mark << " " << fixed << setprecision(1) << arr[imax].engine << " " << arr[imax].color << endl;
    return 0;
}*/

/*2. Опишите структуру Book (название книги, автор, год издания, цена ).
 Создайте массив книг из 6 элементов. Заполните массив данными,
 считав их с консоли. Информация о каждой книге вводится с новой строки,
 а элементы разделяются точкой с запятой.
 Затем пользователь вводит год издания.
 Нужно вывести все книги этого года издания на консоль
 (данные разделяются символом '/', информация о каждой книге с новой строки).
 Также подсчитать среднюю цену на книги, изданные в этом году.
 Средняя цена выводится на консоль с округлением до двух знаков
 после десятичной точки.
 Если в массиве отсутствуют  данные по введенному году издания,
 то следует вывести на консоль "ERROR".
 Рекомендация. Можно ввести данные о книге одной строкой,
 а затем для  разбора строки использовать функцию strtok().
 А для преобразования строки в число использовать atoi() и atof().
 Sample Input:
 Как привести дела в порядок;Девид Аллен;2009;30.32
 Алгоритмы: построение и анализ;Томас Кормен;2019;200.45
 Head First C: A Brain-Friendly Guide;David Griffiths;2009;55.54
 Язык программирования С;Брайан Керниган;2020;44.29
 Объектно-ориентированное программирование в С++;Роберт Лафоре;2020;47.82
 С++. Базовый курс;Герберт Шилдт;2019;39.05
 2020
 Sample Output:
 Язык программирования С/Брайан Керниган/2020/44.29
 Объектно-ориентированное программирование в С++/Роберт Лафоре/2020/47.82
 46.05
 */
/*
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct Book {
    char caption[128];
    char author[128];
    int year;
    double price;
};
int main() {
    //setlocale(LC_ALL, "rus");
    const int N = 6;
    Book arr[N];
    for (int i = 0; i < N; i++) {
        char input[128*3];
        fgets(input, 128*3, stdin);
        //ввод данных в структуру Book
        char* word;
        word = strtok(input, ";");
        strcpy(arr[i].caption, word);
        word = strtok(NULL, ";");
        strcpy(arr[i].author, word);
        word = strtok(NULL, ";");
        arr[i].year = atoi(word);
        word = strtok(NULL, ";");
        arr[i].price = atof(word);
    }
    int year;
    cin >> year;
    int k = 0;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if(arr[i].year == year) {
            cout << arr[i].caption << "/" << arr[i].author << "/" << arr[i].year << "/" << fixed << setprecision(2) << arr[i].price << endl;
            k++;
            sum += arr[i].price;
        }
    }
    if(k == 0)
        cout << "ERROR" << endl;
    else
        cout << (double)sum / k << endl;
    return 0;
}*/

/*
//Lesson_5.3 example_1
#include <iostream>
using namespace std;
//структура студент
struct Student {
    char* surname;
    char* name;
    int age;
};
void readStudent(Student& item) {
    const int MAXLEN = 300;
    char buffer[MAXLEN];
    fgets(buffer, MAXLEN, stdin);
    char* word = strtok(buffer, ";\n");
    item.surname = new char[strlen(word) + 1];
    strcpy(item.surname, word);
    word = strtok(NULL, ";\n");
    item.name = new char[strlen(word) + 1];
    strcpy(item.name, word);
    word = strtok(NULL, ";\n");
    item.age = atoi(word);
}
void printList(Student* spisok, int n) {
    cout << "\nСписок студентов:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << spisok[i].surname << " " << spisok[i].name << " ";
        cout << spisok[i].age << endl;
    }
}
int menu() {
    int choice;
    do {
        cout << "\n1 - добавление студента\n";
        cout << "2 - удаление студента\n";
        cout << "3 - печать списка студентов\n";
        cout << "4 - завершение работы программы\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        if(choice < 1 || choice > 4) {
            cout << "Неверный выбор! Повторите ввод!";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}
void insertStudent(Student *&spisok, int& n) {
    cout << "Введите данные нового студента: ";
    Student item;
    while (cin.get() != '\n');
    readStudent(item);
    //создание нового массива на одного студента больше
    Student* nspisok = new Student[n + 1];
    //копирование данных
    for (int i = 0; i < n; i++) {
        nspisok[i] = spisok[i];
    }
    //добавление нового студента в массив
    nspisok[n] = item;
    //удаляем старый назначаем указатель на новый
    delete[] spisok;
    spisok = nspisok;
    //изменяем количество студентов в массиве
    n++;
}
void deleteStudent(Student *&spisok, int& n) {
    cout << "Введите номер студента, которого нужно удалить: ";
    int k; //номер удаляемого из списка студента
    cin >> k;
    //если ввод неправильный
    if (k < 1 || k > n) return;
    //создание нового массива на одного студента меньше
    Student* nspisok = new Student[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++) {
        //если нужный номер не копируем
        if (i == k - 1) continue;
        nspisok[j++] = spisok[i];
    }
    delete[] spisok[k - 1].surname;
    delete[] spisok[k - 1].name;
    delete[] spisok;
    spisok = nspisok;
    n--;
}
void destroy(Student *spisok, int n) {
    for (int i = 0; i < n; i++) {
        delete[] spisok[i].surname;
        delete[] spisok[i].name;
    }
    delete[] spisok;
}
int main() {
    int n; //текущее количество студентов
    cin >> n;
    while(cin.get() != '\n');
    Student* spisok = new Student[n];
    for(int i = 0; i < n; i++) {
        readStudent(spisok[i]);
    }
    printList(spisok, n);
    while (true) {
        int choice = menu();
        switch (choice) {
            case 1: insertStudent(spisok, n); break;
            case 2: deleteStudent(spisok, n); break;
            case 3: printList(spisok, n); break;
            case 4: cout << "Завершение...";
                    destroy(spisok,n);
                    return 0;
        }
    }
    return 0;
}*/

/*3. Опишите структуру Employee (Сотрудник).
 Для каждого сотрудника нужно хранить ФИО, пол, возраст, стаж работы.
 Пользователь вводит исходное количество сотрудников, а затем данные о них.
 Информация о каждом сотруднике вводится с новой строки, ее части отделяются решеткой ('#').
 Затем пользователь вводит номер в списке, на место которого нужно вставить
 данные о новом человеке, а с новой строки - сами данные.
 Если этот номер неверный (меньше единицы или больше текущего числа сотрудников+1),
 то следует распечатать итоговый список сотрудников, а затем закончить работу программы.
 В противном случае в массив добавляются новые данные, и редактирование списка
 продолжается до тех пор, пока пользователь не введет неверный номер.
 При выводе списка сотрудников элементы данных отделяются пробелами.
 Не забывайте освобождать динамическую память в конце программы!
Sample Input:
3
Смирнов Андрей Евгеньевич#мужской#45#10
Семенов Павел Викторович#мужской#36#3
Самсонова Ольга Николаевна#женский#53#25
2
Корзун Раиса Дмитриевна#женский#39#12
5
Тимофеенко Валентина Степановна#женский#25#1
-1
Sample Output:
Смирнов Андрей Евгеньевич мужской 45 10
Корзун Раиса Дмитриевна женский 39 12
Семенов Павел Викторович мужской 36 3
Самсонова Ольга Николаевна женский 53 25
Тимофеенко Валентина Степановна женский 25 1*/

#include <iostream>
using namespace std;
struct Employee {
    char* fio;
    char* gender;
    int age;
    int experience;
};
void readEmployee(Employee &item) {
    const int MAXLEN = 300;
    char record[MAXLEN];
    fgets(record, MAXLEN, stdin);
    //разбор принятой строки
    char* word;
    long len;
    //ввод ФИО
    word = strtok(record, "#");
    len = strlen(word);
    char* p = new char[len + 1];
    strcpy(p, word);
    item.fio = p;
    //ввод пола
    word = strtok(NULL, "#");
    len = strlen(word);
    p = new char[len + 1];
    strcpy(p, word);
    item.gender = p;
    //ввод возраста
    word = strtok(NULL, "#");
    item.age = atoi(word);
    //ввод стажа
    word = strtok(NULL, "#");
    item.experience = atoi(word);
}
void insertEmployee(Employee *&spisok, int &n, int pos) {
    Employee item;
    while (cin.get() != '\n');
    readEmployee(item);
    //создать новый список
    Employee* nspisok = new Employee[n + 1];
    int j = 0;
    for (int i = 0; i < n + 1; i++) {
        if(i == pos - 1) {
            nspisok[i] = item;
        } else {
            nspisok[i] = spisok[j++];
        }
    }
    delete[] spisok;
    spisok = nspisok;
    n++;
}
void printList(Employee* spisok, int n) {
    for (int i = 0; i < n; i++) {
        cout << spisok[i].fio << " " << spisok[i].age << " " << spisok[i].experience << endl;
    }
}
void destroy(Employee *spisok, int n) {
    for(int i = 0; i < n; i++) {
        delete[] spisok[i].fio;
        delete[] spisok[i].gender;
    }
    delete[] spisok;
}
int main() {
    int n;
    cin >> n;
    while (cin.get() != '\n');
    Employee* spisok = new Employee[n];
    for(int i = 0; i < n; i++) {
        readEmployee(spisok[i]);
    }
    while (true) {
        int pos;
        cin >> pos;
        if(pos < 1 || pos > n + 1) {
            printList(spisok, n);
            destroy(spisok, n);
            return 0;
        } else {
            insertEmployee(spisok, n, pos);
        }
    }
    return 0;
}
