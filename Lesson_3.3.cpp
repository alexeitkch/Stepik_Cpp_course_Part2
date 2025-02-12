// Основы программирования на С/С++. Часть 2.
// Lesson_3.3 Дополнительные задания по теме - Управление динамической памятью
//

/*1. Создайте динамический одномерный массив целых чисел. 
Пользователь вводит число элементов массива и значения этих элементов. 
Затем пользователь вводит контрольное значение. 
Нужно удалить из массива все элементы, меньшие этого контрольного значения. 
Новый массив должен занимать ровно столько памяти, сколько необходимо.
Выведите  массив на консоль, отделяя элементы пробелами.*/
/*
#include <iostream>
using namespace std;
//put your code here
int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int contr;
    cin >> contr;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= contr)
            count++;
    }
    int* b = new int[count];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= contr) {
            b[j] = a[i];
            j++;
        }
    }
    delete[] a;
    a = b;
    n = count;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
*/

/*2. Сформируйте динамический одномерный массив. 
Заполните его случайными числами от -5 до 5. 
Число элементов массива и начальное значение генератора вводит пользователь. 
Выведите исходный массив на консоль, отделяя элементы пробелами.
Продублируйте все отрицательные элементы. 
Преобразованный массив должен занимать ровно столько памяти, сколько ему необходимо. 
Выведите  массив с новой строки .
Оформите инициализацию массива, вывод на консоль и преобразование отдельными функциями.*/
/*
#include <iostream>
using namespace std;
void initArr(int* a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 11 - 5;
}
void printArr(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//продублировать все отрицательные элементы.
void transform(int*& a, int& n) {
    int countNegative = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) countNegative++;
    }
    int* b = new int[n + countNegative];
    int j = 0;
    for (int i = 0; i < n; i++) {
        b[j++] = a[i];
        if (a[i] < 0) {
            b[j++] = a[i];//дублируем отрицательный элемент
        }
    }
    delete[] a;
    a = b;
    n = n + countNegative;
}
int main() {
    //число элементов массива и начальное значение генератора
    int n, start;
    cin >> n >> start;
    srand(start);
    //создание, заполнение и вывод на консоль динамического массива на n элементов
    int* a = NULL;
    a = new int[n];
    initArr(a, n);
    printArr(a, n);
    //преобразование и вывод на консоль массива
    transform(a, n);
    printArr(a, n);
    //удаление массива
    delete[] a;
    a = NULL;
	return 0;
}*/

/*3.Сформируйте динамический одномерный массив. 
Заполните его случайными числами от -10 до 10. 
Число элементов массива и начальное значение генератора вводит пользователь. 
Выведите исходный массив на консоль, отделяя элементы пробелами.
Найдите в массиве последний максимальный элемент и удалите все элементы, 
которые находятся после него. Преобразованный массив должен занимать ровно столько памяти, 
сколько ему необходимо. Выведите  массив с новой строки .
Оформите инициализацию массива, вывод на консоль и преобразование отдельными функциями.*/
/*
#include <iostream>
using namespace std;
void initArr(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 21 - 10;
    }
}
void printArr(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void transformArr(int*& a, int& n) {
    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (a[indexMax] <= a[i])
            indexMax = i;
    }
    int s = n - (indexMax + 1);
    int* b = new int[s];
    for (int i = 0; i < s; i++) {
        b[i] = a[i];
    }
    delete[] a;
    a = b;
    n = s;
}
int main() {
    int n, start;
    cin >> n >> start;
    srand(start);
    int* a = new int[n];
    initArr(a, n);
    printArr(a, n);
    transformArr(a, n);
    printArr(a, n);
    delete[] a;
    a = NULL;
    return 0;
}*/

/*4. Напишите функцию, которая проверяет, 
является ли данная квадратная матрица "магическим квадратом". 
При этом "магическим квадратом" называется матрица, в которой 
сумма чисел в каждом горизонтальном ряду, в каждом вертикальном 
и по обоим диагоналям одна и та же: 
Пользователь вводит размер матрицы, а затем построчно ее элементы. 
Программа должна распечатывать YES, если это магический квадрат, 
и NO - если нет.*/
/*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    //создание динамического массива
    int** ptrArr = new int* [n];
    for (int i = 0; i < n; i++) {
        ptrArr[i] = new int[n];
    }
    //заполнение массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ptrArr[i][j];
        }
    }
    //массив для накопления сумм
    int m = 2 * n + 2;
    int* sum = new int[m];
    //обнуление массива
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //n сумм по строкам
            sum[i] += ptrArr[i][j];
            //n сумм по столбцам
            sum[i + n] += ptrArr[j][i];
            //сумма элементов главной диагонали
            if (j == i) {
                sum[m - 2] += ptrArr[j][i];
            }
            //сумма элементов побочной диагонали
            if (j == (n - i - 1))
                sum[m - 1] += ptrArr[j][i];
        }
    }
    //cout << endl;
    bool flag = true;
    int sum1 = sum[0];
    for (int i = 0; i < m; i++) {
        if (sum1 != sum[i])
            flag = false;
        //cout << sum[i] << " ";
    }
    //cout << endl;
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    //удаление динамических массивов
    delete[] sum;
    for (int i = 0; i < n; i++) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
    return 0;
}*/


/*5.Сформируйте  динамический двумерный массив. 
Заполните его случайными числами от 1 до 10 (заполнение производите построчно). 
Пользователь вводит через пробел число строк, число столбцов и начальное значение генератора.
Распечатайте исходный массив в виде таблицы, отделяя элементы в строке знаками табуляции 
(табуляция должна быть и после последнего элемента строки).
Определите номер строки, содержащей первый максимальный элемент массива.
Продублируйте эту строку (вставьте после данной строки еще одну такую же).
Затем пропустите одну строку и распечатайте преобразованный массив.
Каждое действие с двумерным массивом (инициализация, печать, поиск нужной строки, вставка строки)
оформите отдельной функцией, вызываемой из main().*/

/*
#include <iostream>
using namespace std;
void initArr(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 10 + 1;
        }
    }
}
void printArr(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
int seekString(int** a, int m, int n) {
    int maxi = 0, maxj = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[maxi][maxj] < a[i][j]) {
                maxi = i;
                maxj = j;
            }
        }
    }
    return maxi;
}
void insertString(int**& a, int& m, int n, int k) {
    int** b = new int* [m + 1];
    //переназначение указателей до позиции k
    for (int i = 0; i < k + 1; i++) {
        b[i] = a[i];
    }
    //создание новой строки и копирование строки k
    b[k + 1] = new int[n];
    for (int i = 0; i < n; i++) {
        b[k + 1][i] = a[k][i];
    }
    for (int i = k + 2; i < m + 1; i++) {
        b[i] = a[i - 1];
    }
    delete[] a;
    a = b;
    m = m + 1;
}
int main() {
    int m, n, start;
    cin >> m >> n >> start;
    srand(start);
    //создание динамического массива
    int** ptrArr = new int* [m];
    for (int i = 0; i < m; i++) {
        ptrArr[i] = new int[n];
    }
    initArr(ptrArr, m, n);
    printArr(ptrArr, m, n);
    int k = seekString(ptrArr, m, n);
    //cout << k << endl;
    insertString(ptrArr, m, n, k);
    cout << endl;
    printArr(ptrArr, m, n);
    //удаление динамического массива
    for (int i = 0; i < m; i++) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
    return 0;
}*/

/*6. Транспонирование матрицы - это операция, после которой столбцы 
прежней матрицы становятся строками, 
а строки - столбцами. Напишите функцию транспонирования матрицы.
В функции main() пользователь вводит количество строк, количество 
столбцов и начальное значение генератора. Затем создается двумерный массив 
и инициализируется случайными числами от -10 до 15.
Исходный массив выводится на консоль в виде таблицы, при этом элементы в строке 
отделяются знаками табуляции (табуляция должна быть и после последнего элемента строки).
Затем выполняется транспонирование матрицы и преобразованная матрица вновь выводится на консоль. 
Между выводом исходной матрицы и преобразованной вставьте пустую строку.
Внимание! Не достаточно просто распечатать матрицу в транспонированном виде. 
Она должна в таком виде существовать в памяти! Представьте, что с ней будут 
проводится какие-то дальнейшие преобразования.
Каждое действие с двумерным массивом (инициализация, печать, транспонирование) 
оформите отдельной функцией, вызываемой из main().*/


#include <iostream>
using namespace std;
void initArr(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 26 - 10;
        }
    }
}
void printArr(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void transpon(int**& a, int& m, int& n) {
    //создание массива на n строк и m столбцов
    int** b = new int* [n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = a[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
    a = b;
    int tmp = m;
    m = n;
    n = tmp;
}
int main() {
    int m, n, start;
    cin >> m >> n >> start;
    srand(start);
    //создание динамического массива
    int** ptrArr = new int* [m];
    for (int i = 0; i < m; i++) {
        ptrArr[i] = new int[n];
    }
    initArr(ptrArr, m, n);
    printArr(ptrArr, m, n);
    transpon(ptrArr, m, n);
    cout << endl;
    printArr(ptrArr, m, n);
    //удаление динамического массива
    for (int i = 0; i < m; i++) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
    return 0;
}
