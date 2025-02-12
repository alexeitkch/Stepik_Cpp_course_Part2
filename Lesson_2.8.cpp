// Lesson_2.8 Еще про параметры функций. Перегрузка и шаблоны.

/*1. Напишите функцию с переменным числом параметров типа int, 
которая вычисляет среднее арифметическое этих параметров. 
Первым обязательным параметром передается количество далее следующих чисел.
Вызов этой функции представлен в функции main().*/
/*
#include <iostream>
#include <stdarg.h>
using namespace std;
double average(int a, ...) {
    va_list p;
    va_start(p, a);
    int sum = 0;
    int tmp = va_arg(p, int);
    for (int i = 0; i < a; i++) {
        sum += tmp;
        tmp = va_arg(p, int);
    }
    va_end(p);
    return (double)sum / a;
}
int main() {
    cout << average(3, 5, 7, 12) << " " << average(5, 1, 8, 3, 2, -5);
    return 0;
}*/

/*2. Напишите функцию mymax() с переменным числом параметров, 
которая вычисляет максимум нескольких чисел. Функция возвращает значение типа double. 
Первым обязательным параметром является количество анализируемых чисел. 
Второй обязательный параметр - это признак типа этих чисел. 
Если это символ 'd', то все следующие числа имеют тип int. 
Если же это символ 'f' - то числа вещественные и имеют тип double.
В функции main() продемонстрировано несколько примеров вызова этой функции.*/
/*
#include <iostream>
#include <stdarg.h>
using namespace std;
double mymax(int a, char b, ...) {
    va_list p;
    va_start(p, b);
    double tmp = 0.0;
    if(b == 'd')
        tmp = va_arg(p, int); //type
    if(b == 'f')
        tmp = va_arg(p, double); //type
    for (int i = 1; i < a; i++) {
        double t = 0.0;
        if(b == 'd')
            t = va_arg(p, int); //type
        if(b == 'f')
            t = va_arg(p, double); //type
        if (tmp < t)
            tmp = t;
    }
    return tmp;
}
int main() {
    cout << mymax(5, 'd', 3, 6, 7, -2, 1) << endl;
    cout << mymax(3, 'f', -2.3, 3.14, 0.72) << endl;
    cout << mymax(6, 'f', -13., 0.23, 6.6, 4.56, 0.0, -1.1);
    return 0;
}*/

/*5. Нужно написать функцию  maximum(), которая возвращает указатель 
на первый максимальный элемент массива. 
Чтобы функция работала с массивами любого типа, используйте шаблон. 
Также напишите функцию read(), которая вводит элементы массива, а также функцию print(), 
которая выводит элементы массива на консоль в одну строку, отделяя их пробелами 
(пробел и после последнего элемента массива, а затем курсор переводится на новую строку). 
Используйте формат вывода по умолчанию для cout (не задавайте формат).
В функции main() объявите массив из целых чисел типа int из 10 элементов, массив типа  
double из  7 элементов и массив типа char из 5 элементов. Введите данные в эти массивы. 
Затем найдите в каждом из них максимум и замените его нулем (для массивов int и double) 
либо пробелом (для массива типа char). Выведите преобразованные массивы на консоль.*/

#include <iostream>
using namespace std;
template <typename T>
void read(T* a, int n) {
    for (int i = 0; i < n; i++, a++)
        cin >> *a;
}

template <typename T>
void print(T* a, int n) {
    for (int i = 0; i < n; i++, a++)
        cout << *a << " ";
    cout << endl;
}
/*
//variant1
template <typename T>
T* maximum(T* a, int n) {
    T *max = a;
    for (int i = 1; i < n; i++, a++) {
        if (*max < *a) 
            max = a;
    }
    return max;
}*/

//variant2
template <typename T>
T* maximum(T* a, int n) {
    int imax = 0;
    for (int i = 1; i < n; i++) {
        if (a[imax] < a[i])
            imax = i;
    }
    return &a[imax];
}

//variant3
template <typename T>
T* maximum(T* a, int n) {
    T max = 0;
    for (int i = 1; i < n; i++) {
        if (max< a[i])
            max = a[i];//адрес max не равен a[i]
    }
    //ошибка в этом случае отправляется указатель на переменную max 
    //а не указатель на элемент массива!!!!
    return &max;
}

int main() {
    const int N = 10;
    const int M = 7;
    const int K = 5;
    int a[N];
    double b[M];
    char c[K];
    read(a, N);
    read(b, M);
    read(c, K);
    *maximum(a, N) = 0;
    *maximum(b, M) = 0;
    *maximum(c, K) = ' ';
    print(a, N);
    print(b, M);
    print(c, K);
    return 0;
}