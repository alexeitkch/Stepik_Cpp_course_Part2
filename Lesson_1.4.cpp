// Lesson_1.4
//
/*
#include <iostream>
using namespace std;
int main()
{
    int a[] = { 3,6,7,5,4 };
    int* ptr = a + 3;
    //значение *ptr сначала выводится 5 а потом изменяется ++ 6
    cout << *ptr++;
}
*/


/*1.Создать массив из 12 целых чисел. 
Заполнить массив случайным образом в диапазоне от -45 до 45 
(начальное значение генератора случайных чисел запросить у пользователя).
Вывести исходный массив на консоль в одной строке, разделяя элементы пробелами. 
Пробел должен быть в том числе и после последнего элемента массива. 
Подсчитать процент положительных и процент отрицательных элементов массива. 
Результаты распечатать на следующей строке co знаком %. 
Проценты округлить до одного знака после десятичной точки. Разделить пробелом.*/
/*
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const int SIZE = 12;
    int arr[SIZE];
    int start;
    cin >> start;
    srand(start);
    int sumEl = 0, sumPos = 0, sumNeg = 0;

    //заполнение исходного массива
    int* ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 91 - 45;
        sumEl++;
        if (*ptr > 0)
            sumPos++;
        if (*ptr < 0)
            sumNeg++;
    }

    //вывод массива на консоль
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    //подсчет процента положительных значений массива
    double prPos = (double)sumPos / sumEl * 100;
    //подсчет процента отрецательных значений массива
    double prNeg = (double)sumNeg / sumEl * 100;
    cout << fixed << setprecision(1) << prPos << "% " << prNeg << "%" << endl;
    return 0;
}
*/

/*2.Введите с консоли элементы массива из 7 целых чисел.
Воспользовавшись указателями, поменяйте местами элементы массива 
с четными и нечетными индексами. Последний элемент массива должен остаться на своем месте.
Преобразованный массив выведите на консоль, отделяя элементы пробелами. 
Пробел должен быть и в конце массива.*/
/*
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 7;
    int arr[SIZE];
    int* ptr = arr;

    //ввод исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        cin >> *ptr;
    }
    
    ptr = arr;
    for (int i = 0; i < SIZE-1; i++, ptr++) {
        if (i % 2 == 0) {
            int tmp = *ptr;
            *ptr = *(ptr+1);
            *(ptr+1) = tmp;
        }
    }
    
    //вывод измененного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int start;
    cin >> start;
    srand(start);

    //заполнение и вывод на консоль исходного массива
    int* ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 41 - 20;
        cout << *ptr << " ";
    }
    cout << endl;

    //вывод изменунного массива на консоль
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
*/

/*3.Создать массив из 10 целых чисел. 
Заполнить массив случайным образом в диапазоне от -20 до 20 
(начальное значение генератора случайных чисел запросить у пользователя).
Вывести исходный массив на консоль в одной строке, разделяя элементы пробелами. 
Пробел должен быть в том числе и после последнего элемента массива. 
Пользуясь ДВУМЯ указателями, нужно поменять порядок элементов массива на обратный.
С новой строки вывести преобразованный массив, разделяя элементы пробелами.*/
/*
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int start;
    cin >> start;
    srand(start);
    //заполнение и вывод на консоль исходного массива
    int* ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 41 - 20;
        cout << *ptr << " ";
    }
    cout << endl;
    //изменение порядка элементов массива
    ptr = arr;
    int* ptr2 = arr + SIZE - 1;
    for (int i = 0; i < SIZE / 2; i++, ptr++, ptr2--) {
        int tmp = *ptr;
        *ptr = *ptr2;
        *ptr2 = tmp;
    }
    //вывод измененного массива на консоль
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
*/

/* Пример 1.4
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    const int N = 10;
    int a[N] = { -8,-4,3,4,7,15,21,25,31,42 };
    const int M = 5;
    int b[M] = { -5,0,1,9,10 };
    int c[N + M];
    //каждый указатель - на начало соответствующего массива
    int* ptrA = a;
    int* ptrB = b;
    int* ptrC = c;
    //пока оба указателя находятся в пределах своих массивов
    while (ptrA < a + N && ptrB < b + M) {
        if (*ptrA < *ptrB) {
            *ptrC = *ptrA; //переписываем значение из массива a
            ptrA++;
        }
        else {
            *ptrC = *ptrB; //переписываем значение из массива b
            ptrB++;
        }
        ptrC++; //указатель в массиве с - на следующее свободное место
    }
    //пока не закончился массив a, переписываем из него все подряд
    while (ptrA < a + N) {
        *ptrC = *ptrA;
        ptrA++;
        ptrC++;
    }
    //пока не закончился массив b, переписываем из него все подряд
    while (ptrB < b + M) {
        *ptrC = *ptrB;
        ptrB++;
        ptrC++;
    }
    //печать сформированного массива c
    int* ptr = c;
    for (int i = 0; i < N + M; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}
*/