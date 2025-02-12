//  Stepik.org 
//  Основы программирования на С/С++ Часть 2 
//  Раздел 3. Управление динамической памятью
//  Урок 3.2 Многомерные динамические массивы
//  Решение задач.
//  Lesson_3.2
//
//  Created by Aleksey on 09.02.2025.
//

/*1. У пользователя запрашиваются размеры двумерного массива 
и начальное значение генератора случайных чисел 
(данные вводятся через пробел: сначала количество строк, потом столбцов, 
а потом число для инициализации генератора).
Нужно заполнить массив случайными числами от -5 до 5 и 
вывести массив на консоль в виде таблицы (элементы в строке отделяются знаками табуляции). 
С новой строки консоли вывести максимальные элементы  всех строк массива через пробел.*/
/*
#include <iostream>
using namespace std;
void initArray(int** a, int m, int n) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = rand() % 11 - 5;
}
void printArray(int** a, int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void maxString(int** a, int m, int n) {
    for(int i = 0; i < m; i++) {
        int max = a[i][0];
        for(int j = 0; j < n; j++) {
            if(a[i][j] > max)
                max = a[i][j];
        }
        cout << max << " ";
    }
    cout << endl;
}

int main() {
    int m, n, start;
    cin >> m >> n >> start;
    srand(start);
    int** ptrArr = new int*[m];
    for(int i = 0; i < m; i++) {
        ptrArr[i] = new int[n];
    }
    initArray(ptrArr, m, n);
    printArray(ptrArr, m, n);
    maxString(ptrArr, m, n);
    for(int i = 0; i < m; i++) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
    return 0;

} */



/*2. Программа создает "треугольный" динамический массив, 
в котором количество элементов в строке увеличивается от 1 до m 
(где m - количество строк). 
Массив заполняется случайными числами от 10 до 50 и выводится на консоль 
(элементы в строке отделяются знаками табуляции).  
Пользователь вводит требуемое количество строк и 
начальное значение генератора случайных чисел, отделяя их пробелами.*/
/*
#include <iostream>
using namespace std;
int main() {
    int m, start;
    cin >> m >> start;
    srand(start);
    //создание динмического треугольного массива
    int m1 = 1;
    int** ptrArr = new int*[m];
    for(int i = 0; i < m; i++) {
        ptrArr[i] = new int[m1];
        m1++;
    }
    //заполнение динамического массива
    int m2 = 1;
    for(int i = 0; i < m; i++, m2++){
        for(int j = 0; j < m2; j++) {
            ptrArr[i][j] = rand() % 41 + 10;
            cout << ptrArr[i][j] << "\t";
        }
        cout << endl;
    }
    //удаление динамического треугольного массива
    for(int i = 0; i < m; i++) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
    return 0;
} */

/*3. Сформируйте  динамический двумерный массив. 
Заполните его случайными числами от 1 до 10 (заполнение производите построчно). 
Пользователь вводит через пробел число строк, число столбцов и начальное значение генератора.
Распечатайте исходный массив в виде таблицы, отделяя элементы в строке знаками табуляции 
(табуляция должна быть и после последнего элемента строки).
Определите строку, минимальный элемент которой является наибольшим из минимальных элементов  всех строк.
Удалите из массива данную строку (если таких строк несколько, то удалите первую из них).
Затем пропустите одну строку и распечатайте преобразованный массив.
Каждое действие с двумерным массивом 
(инициализация, печать, поиск нужной строки, удаление строки) оформить отдельной функцией, вызываемой из main().*/

#include <iostream>
using namespace std;
void initArray(int* a[], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 10 + 1;
}
void printArray(int* a[], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
int stringSeek(int* a[], int m, int n) {
    //int minArr[m];
    int* minA = new int [m];
    for (int i = 0; i < m; i++) {
        int min = a[i][0];
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min)
                min = a[i][j];
        }
        //массив минимальных значений строк
        minA[i] = min;
    }
    //поиск индекса макс из минимальных
    int minMaxInd = 0;
    for (int i = 0; i < m; i++) {
        if (minA[minMaxInd] < minA[i])
            minMaxInd = i;
    }
    delete[] minA;
    minA = NULL;
    //cout << minMaxInd << endl;
    return minMaxInd;
}
void stringDelete(int**& a, int& m, int n, int ind) {
    int** b = new int* [m - 1];
    int j = 0;
    for (int i = 0; i < m; i++) {
        if (i != ind) {
            b[j] = a[i];
            j++;
        }
    }
    delete[] a;
    a = b;
    m = m - 1;
}
int main() {
    int m, n, start;
    cin >> m >> n >> start;
    srand(start);
    int** ptArr = new int* [m];
    for (int i = 0; i < m; i++) {
        ptArr[i] = new int[n];
    }
    initArray(ptArr, m, n);
    printArray(ptArr, m, n);
    int index = stringSeek(ptArr, m, n);
    stringDelete(ptArr, m, n, index);
    cout << endl;
    printArray(ptArr, m, n);
    for (int i = 0; i < m; i++) {
        delete[] ptArr[i];
    }
    delete[] ptArr;
    ptArr = NULL;
    return 0;
}