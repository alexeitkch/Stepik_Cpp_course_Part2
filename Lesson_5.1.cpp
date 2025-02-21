// Lesson_5.1 Структуры: объявление и использование
//

/*2.Объявить структуру Tovar (название товара, страна-производитель, цена).  
Создать массив из 7 элементов типа Tovar. Заполнить массив данными, считав их с консоли. 
Информация о каждом товаре вводится с новой строки, 
а элементы разделяются одним или несколькими пробелами.
Затем вводится название страны. 
На консоль выводится список товаров, 
произведенных в этой стране (каждый товар с новой строки). 
И затем с новой строки выводится средняя цена на товары из этой страны. 
Среднюю цену представьте с двумя знаками после точки.
Если же товаров из этой страны нет в списке, 
нужно вывести на консоль слово "Error".
Sample Input:
Молоко Беларусь 1.58
Сахар Украина 1.9
Творог Беларусь 2.5
Бананы Эквадор 3.2
Сметана Беларусь 2.1
Шоколад Россия 4.5
Мука Россия 3.1
Беларусь
Sample Output:
Молоко Беларусь 1.58
Творог Беларусь 2.5
Сметана Беларусь 2.1
2.06
*/
/*
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Tovar {
    char name[30];
    char madein[30];
    double price;
};
int main() {
    const int N = 7;
    Tovar arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].name >> arr[i].madein >> arr[i].price;
        //while (cin.get() != '\n');
    }
    char city[30];
    cin >> city;
    int k = 0;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(city, arr[i].madein) == 0) {
            cout << arr[i].name << " " << arr[i].madein << " " << arr[i].price << endl;
            k++;
            sum += arr[i].price;
        }   
    }
    if (k == 0) {
        cout << "Error" << endl;
    }
    else {
        cout << fixed << setprecision(2) << (double)sum/k << endl;
    }
    return 0;
}*/

/*3. Опишите структуру Student (фамилия, имя, группа, возраст в годах, средний балл). 
Создайте массив из 8 элементов типа Student. Заполните массив данными, 
считав их с консоли. Информация о каждом студенте вводится с новой строки, 
а элементы разделяются одним или несколькими пробелами.
Затем вводится название группы. 
Вывести список отличников этой группы (средний балл которых больше 8.0).  
Подсчитать средний возраст этих отличников. 
Информация о каждом выбранном студенте выводится с новой строки, 
поля отделяются одним пробелом. Средний балл студента не форматируйте. 
Затем с новой строки выводится средний возраст. 
Он должен быть откруглен до одного знака после десятичной точки.
Если в указанной группе нет отличников (или вообще нет такой группы), то выводится "Error".

Sample Input:
Иванов Андрей     S-11  21 6.7
Смирнова Ольга    G-11 23 8.6
Агеенко   Сергей S-11 18 9.2
Толкачева Анна     S-11  22 8.4
Семенов Антон  G-11 17 5.7
Сморыгин Евгений S-11 32 7.8
Велесов Дмитрий     S-11 30 8.7
Меркулова Дарья G-11   17  9.8
S-11

Sample Output:
Агеенко Сергей S-11 18 9.2
Толкачева Анна S-11 22 8.4
Велесов Дмитрий S-11 30 8.7
23.3
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Student {
    char surname[30];
    char name[30];
    char group[30];
    int age;
    double averageBall;
};
int main() {
    const int N = 8;
    Student arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].surname >> arr[i].name >> arr[i].group >> arr[i].age >> arr[i].averageBall;
    }
    char word[30];
    cin >> word;
    int k = 0;
    int ageSum = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(word, arr[i].group) == 0) {
            if (arr[i].averageBall > 8.0) {
                cout << arr[i].surname << " " << arr[i].name << " " << arr[i].group << " " << arr[i].age << " " << arr[i].averageBall << endl;
                ageSum += arr[i].age;
                k++;
            }
        }
    }
    if (k == 0)
        cout << "Error" << endl;
    else
        cout << fixed << setprecision(1) << (double)ageSum / k << endl;
    return 0;
}
