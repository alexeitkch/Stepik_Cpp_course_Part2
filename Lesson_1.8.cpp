// Lesson_1.8
//

/*1.Массив целых чисел из 10 элементов заполнить случайными числами от -5 до 5 
(начальное значение генератора случайных чисел запросить у пользователя). 
Вывести исходный массив на консоль, отделяя элементы пробелами. 
Пробел должен быть и после последнего элемента.
Все отрицательные элементы массива заменить нулями.
Вывести преобразованный массив на консоль c новой строки, отделяя элементы пробелами.*/
/*
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int SIZE = 10;
    int arr[SIZE];
    int* ptr = arr;
    //заполнение исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 11 - 5;
    }

    //вывод исходного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    //работа с массивом
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        if (*ptr < 0)
            *ptr = 0;
    }

    //вывод преобразованного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
*/

/*2.
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int SIZE = 15;
    int arr[SIZE];
    int* ptr = arr;

    //заполнение исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 21 - 10;
    }
    //вывод исходного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    //работа с массивом
    ptr = arr;
    int* ptr1 = NULL;
    int* ptr2 = arr;
    int sum = 0, cnt = 0;
    double avr;
    bool flag = false;
    for (int i = 0; i < SIZE; i++, ptr++) {
        //первый отрицательный элемент массива
        if (*ptr < 0 && ptr1 == NULL)
            ptr1 = ptr;
        //поиск последнего максимального элемента массива
        if (*ptr >= *ptr2)
            ptr2 = ptr;
    }
    if (ptr1 == NULL) {
        cout << "ERROR" << endl;
        return 0;
    }
    //количество элементов между указателями
    if (ptr2 > ptr1) {
        cnt = ptr2 - ptr1 + 1;
        //сумма между указателями
        while (ptr1 <= ptr2) {
            sum += *ptr1;
            ptr1++;
        }
    }
    else {
        cnt = ptr1 - ptr2 + 1;
        //сумма между указателями
        while (ptr2 <= ptr1) {
            sum += *ptr2;
            ptr2++;
        }
    }
    //подсчет и вывод на консоль среднего арифмитического
    avr = (double)sum / cnt;
    cout << fixed << setprecision(2) << avr << endl;
}
*/

/*3.
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int SIZE = 8;
    int arr[SIZE];
    int* ptr = arr;

    //заполнение исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 13 - 5;
    }
    //вывод исходного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    //преобразование массива
    int* ptrMin = arr;
    int* ptrNeg = NULL;
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        if (*ptr < *ptrMin)
            ptrMin = ptr;
        if (*ptr < 0)
            ptrNeg = ptr;
    }
    if (ptrNeg != NULL) {
        int tmp = *ptrMin;
        *ptrMin = *ptrNeg;
        *ptrNeg = tmp;
    }
    else {
        ptr = arr;
        int tmp = *(ptr + 2);
        *(ptr + 2) = *ptrMin;
        *ptrMin = tmp;
    }

    //вывод преобразованного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
*/

/*4.Массив из двадцати элементов заполнить случайными числами от -1 до 1 
(начальное значение генератора случайных чисел запросить у пользователя). 
Вывести исходный массив на консоль, отделяя элементы пробелами. 
Пробел должен быть и после последнего элемента.
Пользуясь указателями, найти максимальное количество подряд идущих нулей. 
Результат вывести на консоль с новой строки.*/
/*
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int SIZE = 20;
    int arr[SIZE];
    int* ptr = arr;
    //заполнение исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        *ptr = rand() % 3 - 1;
    }
    //вывод исходного массива
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    //подсчет последовательности нулей в массиве
    int sumZerros = 0, sumMax = 0;
    ptr = arr;
    for (int i = 0; i < SIZE; i++, ptr++) {
        if (*ptr == 0) {
            sumZerros++;
            //пока идут нули суммируем
            while (*(++ptr) == 0) { //указатель прибавляется здесь
                sumZerros++;
            }
            //переход на следующую ненулевую позицию
            i += sumZerros;
            //cout << sumZerros << endl;
            //нахождение большей суммы
            if (sumZerros > sumMax)
                sumMax = sumZerros;
            sumZerros = 0;
        }
    }
    cout << sumMax << endl;
    return 0;
}
*/

/*5.Реализовать бинарный поиск в одномерном упорядоченном массиве, пользуясь указателями.
Пользователь вводит отсортированный по возрастанию массив целых 
чисел из 10 элементов, которые не повторяются.
Затем вводится число для поиска. 
Нужно найти это число в массиве и вывести с новой строки часть массива, 
начиная с заданного числа и до конца массива. Элементы отделяются пробелами.
Если искомого числа в массиве нет, то вывести "ERROR".*/
/*
#include <iostream>
using namespace std;
int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int* ptr = arr;
    //ввод исходного массива
    for (int i = 0; i < SIZE; i++, ptr++) {
        cin >> *ptr;
    }
    int search;
    cin >> search;

    //бинарный поиск числа в массиве
    int* find = NULL;
    int* low = arr;
    int* up = arr + SIZE - 1;
    int* middle; // = arr + (up - low) / 2;
    do {
        middle = low + (up - low) / 2;
        if (*middle == search) {
            find = middle;
            break;
        }
        if (search < *middle) up = middle - 1;
        if (search > *middle) low = middle + 1;

    } while (low <= up);
    if (find == NULL)
        cout << "ERROR" << endl;
    else {
        up = arr + SIZE - 1;
        while (find <= up) {
            cout << *find << " ";
            find++;
        }
        cout << endl;
    }
    return 0;
}
*/

/*6.Пользователь вводит начальное значение генератора случайных чисел. 
Сформировать двумерный массив из 4 строк и 5 столбцов, 
заполнив его случайными числами от -10 до 10. 
Распечатать этот массив в виде таблицы, отделяя элементы в строке знаками табуляции 
(знак табуляции должен быть и в конце каждой строки).
Вывести пустую строку.
Затем заполнить нулями все четные строки (с точки зрения пользователя). Вновь вывести полученный массив.*/
/*
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int ROW = 4;
    const int COL = 5;
    int arr[ROW][COL];
    int* ptr = arr[0];
    //заполнение массива
    for (int i = 0; i < ROW * COL; i++, ptr++) {
        *ptr = rand() % 21 - 10;
    }
    //вывод на консоль исходного массива
    ptr = arr[0];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++, ptr++) {
            cout << *ptr << "\t";
        }
        cout << endl;
    }
    cout << endl;
    //вывод на консоль измененного массива
    ptr = arr[0];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++, ptr++) {
            if (i % 2 != 0)
                cout << 0 << "\t";
            else
                cout << *ptr << "\t";
        }
        cout << endl;
    }
    return 0;
}
*/

/*7. Пользователь вводит начальное значение генератора случайных чисел. 
Сформировать двумерный массив из 4 строк и 5 столбцов, заполнив его случайными числами от -10 до 10. 
Распечатать этот массив в виде таблицы, отделяя элементы в строке знаками табуляции 
(знак табуляции должен быть и в конце каждой строки).
Вывести пустую строку.
Сформировать массив указателей на начало каждой строки двумерного массива. 
Отсортировать этот массив указателей так, чтобы первые элементы строк оказались 
в порядке возрастания (сам двумерный массив не изменяется, меняется только массив указателей).
Вывести строки двумерного массива в полученном порядке. Элементы строк отделяются знаками табуляции.*/

/**/
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int ROW = 4;
    const int COL = 5;
    int arr[ROW][COL];
    int* ptr = arr[0];
    //заполнение массива
    for (int i = 0; i < ROW * COL; i++, ptr++) {
        *ptr = rand() % 21 - 10;
    }
    //вывод на консоль исходного массива
    ptr = arr[0];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++, ptr++) {
            cout << *ptr << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //формирование массива указателей
    int* arrPtr[ROW];
    for (int i = 0; i < ROW; i++) {
        arrPtr[i] = arr[i];
    }

    /*сортировка массива указателей пузырьком
    for (int i = ROW - 1; i >= 0; i--) {
        for (int k = 0; k < i; k++) {
            if (*arrPtr[k] > *arrPtr[k + 1]) {
                int* tmp = arrPtr[k];
                arrPtr[k] = arrPtr[k + 1];
                arrPtr[k + 1] = tmp;
            }
        }
    }*/

    /*Более сложный вариант сортировки - на одних указателях*/
    for(int k = ROW - 1; k > 0; k--) {
        int **pPtr = arrPtr;
        for(int i = 0; i < k; i++, pPtr++){
            if(**pPtr > **(pPtr + 1)) {
                int* tmp = *pPtr;
                *pPtr = *(pPtr + 1);
                *(pPtr + 1) = tmp;
            }
        }
    }

    /*
    //вывод значения ссылок массива указателей
    for (int i = 0; i < ROW; i++) {
        cout << *arrPtr[i] << "\t";
    }
    cout << endl;
    */

    //вывод на консоль строк исходного массива
    //в порядке ссылок массива указателй
    for (int i = 0; i < ROW; i++) {
        ptr = arrPtr[i];
        for (int j = 0; j < COL; j++, ptr++) {
            cout << *ptr << "\t";
        }
        cout << endl;
    }
    return 0;
}