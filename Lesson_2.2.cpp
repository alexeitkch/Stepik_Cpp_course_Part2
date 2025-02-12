// Lesson_2.2 Функции и массивы
//
/*3.Напишите функцию определения суммы максимумов в столбцах двумерного массива. 
Также напишите функции инициализации двумерного массива случайными числами от 0 до 10 
и вывода двумерного массива на консоль в виде таблицы. 
Элементы в строке отделяются знаками табуляции.
Все функции должны работать  с массивами, имеющими 4 столбца.
В функции main имеется заготовка с вызовом этих функций. 
Вводится начальное значение генератора случайных чисел. 
Выводится массив и на следующей строке - сумма максимальных элементов его столбцов.*/
/*
#include <iostream>
using namespace std;
#define N 3
#define M 4

void initArray(int a[][M], int);
void printArray(int (*a)[M], int);
int sumOfMax(int a[][M], int);

int main() {
    int n;
    cin >> n;
    srand(n);
    int a[N][M];
    initArray(a, N);
    printArray(a, N);
    int sum = sumOfMax(a, N);
    cout << sum;
    return 0;
}
//инициализация массива
void initArray(int a[][M], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = rand() % 11;
}
//вывод на консоль массива
void printArray(int (*a)[M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
//подсчет суммы максимумов столбцов
int sumOfMax(int a[][M], int n) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
        int max = a[0][j];
        for (int i = 0; i < n; i++) {
            if (a[i][j] > max)
                max = a[i][j];
        }
        sum += max;
    }
    return sum;
}
*/

/*4. */
#include <iostream>
using namespace std;
#define N 4
#define M 5

void initArray(int mas[][M], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < M; j++)
            mas[i][j] = rand() % 13 - 3;
}
void printArray(int mas[][M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    } 
}
int minArray(int m[], int n) {
    int min = m[0];
    for (int i = 0; i < n; i++, m++) {
        if (*m < min)
            min = *m;
    }
    return min;
}

int main() {
    int n;
    cin >> n;
    srand(n);
    int a[N][M];
    initArray(a, N);
    printArray(a, N);
    //поиск минимумов в строках массива
    for (int i = 0; i < N; i++) {
        int min = minArray(a[i], M);//не N а M
        cout << min << " ";
    }
    cout << endl;
    //поиск минимума в массиве
    int min = minArray(&a[0][0], N * M); //можно a[0]
    cout << min << endl;
    return 0;
}