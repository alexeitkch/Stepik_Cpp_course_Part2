// Lesson_2.9 Рекурсия
//

/*1. Напишите функцию, которая выводит цифры положительного целого 
числа слева направо, отделяя их пробелами. Используйте рекурсию. */

/*
//204 -> 2 0 4 с одним нулем проходит с двумя нет 2004 -> 2 0 4
void printNumber(int i) {
    if (i <= 0) return;
    int a = i;
    int b = 1;
    bool flag = false;
    while (a >= 100) {
        a /= 10;
        b *= 10;
    }
    if (a % 10 == 0) flag = true;
    while (a >= 10) {
        a /= 10;
        b *= 10;
    }
    cout << a << " ";
    if (flag) {
        cout << 0 << " ";
        flag = false;
    }
    printNumber(i - a * b);
}*/

/*
//456 -> 6 5 4
void printNumber(int i) {
    if (i == 0) return;
    cout << i % 10 << " ";
    printNumber(i/10);
}
//123 -> 1 2 3
void printNumber(int k) {
    if (k == 0) return;
    printNumber(k / 10);
    cout << k % 10 << " ";
}
*/
/*
#include <iostream>
using namespace std;
int pwr(int num) {
    int pw = 0;
    while (num > 0) {
        num /= 10;
        pw++;
    }
    return pw;
}

void printNumber(int i) {
    if (i <= 0) return;
    int a = i;
    int b = 1;
    while (a >= 10) {
        a /= 10;
        b *= 10;
    }
    cout << a << " ";
    for (int k = pwr(i - a * b); k < pwr(i) - 1; k++)
        cout << 0 << " ";
    printNumber(i - a * b);
}

int main() {
    int k;
    cin >> k;
    printNumber(k);
    cout << endl;
    return 0;
}*/

/*2.Напишите функцию, которая получает в качестве параметров два целых числа a и b. 
Она выводит на консоль все целые числа от a до b в порядке возрастания, если a<b, 
и в порядке убывания в противном случае. Числа отделяются пробелами. 
Если a равно b, то выводится одно число.
Используйте рекурсию!*/
/*
#include <iostream>
using namespace std;
void order(int a, int b) {
    cout << a << " ";
    if (a == b) 
        return;
    if (a < b)
        order(a + 1, b);
    else
        order(a - 1, b);
}
int main() {
    int a, b;
    cin >> a >> b;
    order(a, b);
    return 0;
}*/


/*3.Напишите функцию, которая получает на вход целое положительное число n 
и выдает true, если n является точной степенью двойки, 
и false - в противном случае. 
Нужно использовать рекурсию и нельзя использовать функцию возведения в степень.
Подсказка: если число нечетное, то оно никак не может быть степенью двойки. 
Если же число четное, то нужно его разделить на 2 и проверить, является ли результат деления степенью двойки.
(т.е. единица является степенью двойки)*/
/*
* bool powerOf2(int n) {
    if (n == 1) 
        return true;
    if (n % 2 != 0)
        return false;
    else {
        if (n > 2)
            powerOf2(n / 2);
        else
            if (n == 2)
                return true;
            else
                return false;
    }
}
*/
/*
#include <iostream>
using namespace std;
bool powerOf2(int n) {
    if (n == 1) 
        return true;
    if (n % 2 != 0)
        return false;
    else 
        powerOf2(n / 2);
}
int main() {
    int n;
    cin >> n;
    if (powerOf2(n)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}*/

/*4.
#include <iostream>
using namespace std;

int sumOfNumbers(int n) {
    int sum = 0;
    if (n < 0) n = -n;
    if (n == 0) return sum;
    sum += n % 10;
    sum += sumOfNumbers(n / 10);
}
int main() {
    int n;
    cin >> n;
    cout << sumOfNumbers(n);
    return 0;
}
*/

/*5 Напишите рекурсивную функцию сортировки по не убыванию (возрастанию) методом выбора.
В функции main() вводится начальное значение генератора случайных чисел.
Затем одномерный массив из 10 элементов заполняется случайными числами от 0 до 20 
и выводится на консоль (элементы массива отделяются знаками табуляции). 
Потом вызывается функция сортировки и после нее массив также выводится на консоль с новой строки.
Для красоты кода лучше создать дополнительные функции инициализации элементов 
массива и его вывода на консоль.*/
/* функция min на циклах
void sorting(int* a, int n) {
    for (int k = 0; k < n - 1; k++) {
        int imin = k;
        for (int i = k + 1; i < n; i++) {
            if (a[i] < a[imin])
                imin = i;
        }
        int tmp = a[k];
        a[k] = a[imin];
        a[imin] = tmp;
    }
}
*/
/*
#include <iostream>
using namespace std;
void init(int* a, int n) {
    for (int i = 0; i < n; i++, a++)
        *a = rand() % 21;
}
void print(int* a, int n) {
    for (int i = 0; i < n; i++, a++)
        cout << *a << " ";
    cout << endl;
}
//функция min на рекурсии
void sorting(int* a, int n) {
    if (n == 1) return;
    int imin = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[imin])
            imin = i;
    }
    int tmp = a[0];
    a[0] = a[imin];
    a[imin] = tmp;
    a++;
    return sorting(a, n - 1);
}

int main() {
    int start;
    cin >> start;
    srand(start);
    const int N = 10;
    int a[N];
    init(a, N);
    print(a, N);
    sorting(a, N);
    print(a, N);
    return 0;
}*/

/*6.Для вычисления наибольшего общего делителя двух чисел (НОД) можно использовать алгоритм Евклида:
    НОД(a,b)={    НОД(a−b,b)если a>b
                  a ecли a==b 
                  НОД(a,b−a)если a<b
Словами этот рекурсивный алгоритм можно выразить так: для того, что бы найти НОД двух чисел a и b, 
необходимо их сравнить. 
Если a равно b, то НОД равен a. 
Если же одно из чисел больше другого, то нужно из большего вычесть меньшее, 
и повторно применить этот алгоритм к разности и меньшему из чисел. 
Процесс завершается, когда числа становятся равными.
Реализовать алгоритм Евклида для определения наибольшего общего делителя двух целых чисел.
В функции main() вводятся два числа и вызывается функция nod() для вычисления наибольшего общего делителя.
Результат выводится на консоль.*/
/*
#include <iostream>
using namespace std;
int nod(int a, int b) {
    if (a == b) 
        return a;
    if (a > b) 
        return nod(a - b, b);
    else 
        return nod(a, b - a);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << nod(a, b);
    return 0;
}*/

/*7.*/
/*
#include <iostream>
using namespace std;
void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void mysort(int a[], int l, int r) {
    if (l > r) return; //терминатор
    int c = (l + r) / 2; //индекс середины
    int i = l;
    int j = r;
    while (i < j) {
        while (a[i] <= a[c]) {
            i++;
            cout << "+" << endl;
        }
        while (a[c] < a[j]) {
            j--;
            cout << "-" << endl;
        }
        if (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    print(a, r + 1);
    mysort(a, l, j - 1);
    mysort(a, i + 1, r);
}

int main() {
    const int N = 10;
    int a[N];
    for (int i = 0;i < N;i++) {
        cin >> a[i];
    }
    mysort(a, 0, N - 1);
    print(a, N);
    return 0;
}*/

/*8. ver1
#include <iostream>
#include <math.h>
using namespace std;
void fun(int& x, int& y, int k, int m) {
    if ((y % 10 > x % 10 && x != 0) || y == 0) {
        y = y * 10 + x % 10;
        x /= 10;
        cout << k << "->" << m << endl;
    }
    else {
        x = x * 10 + y % 10;
        y /= 10;
        cout << m << "->" << k << endl;
    }
}

int tower(int kolDisk, int a, int b, int c) {
    static int step = 0;
    static int num = 0;
    static int n = 1;
    static int m = 2;
    int cnt = kolDisk;
    if (step == 0) {
        if(kolDisk % 2 != 0) {
            n = 2;
            m = 1;
        }
        for (int i = 1; i <= kolDisk; i++) {
            num += i * pow(10, i - 1);
        }
        a = num;
        b = 0;
        c = 0;
        cnt = 1;
    }
    //терминальная операция
    if (b == num || c == num) return step;

    //цикл cnt 1..3
    if (cnt > 3) cnt = 1;
    if (cnt == n)
        fun(a, b, 1, 2);
    else if (cnt == m)
        fun(c, a, 3, 1);
    else
        fun(b, c, 2, 3);
    step++;
    cnt++;
    return tower(cnt, a, b, c);
}

int main() {
    int kolDisk;
    cin >> kolDisk;
    int kol = tower(kolDisk, 1, 2, 3);
    cout << "Количество действий: " << kol << endl;
    return 0;
}
*/


/*8. ver2
#include <iostream>
#include <math.h>
using namespace std;
void fun(int& x, int& y, int k, int m) {
    if ((y % 10 > x % 10 && x != 0) || y == 0) {
        y = y * 10 + x % 10;
        x /= 10;
        cout << k << "->" << m << endl;
    }
    else {
        x = x * 10 + y % 10;
        y /= 10;
        cout << m << "->" << k << endl;
    }
}
void shift(int arr[], int n) {
    int tmp = arr[2];
    arr[2] = arr[1];
    arr[1] = arr[0];
    arr[0] = tmp;
}
int fnum(int n) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        num += i * pow(10, i - 1);
    }
    return num;
}
int tower(int kolDisk, int a, int b, int c) {
    static int step = 0;
    static int arr[] = { a, b, c };
    static int i[] = { 1, 2, 3 };
    //cout << a << " " << b << " " << c << endl;
    //инициализация переменных
    if (step == 0) {
        arr[0] = fnum(kolDisk);
        arr[1] = 0;
        arr[2] = 0;
    }
    //терминальная операция
    if (b == fnum(kolDisk) || c == fnum(kolDisk)) return step;
    fun(arr[0], arr[1], i[0], i[1]);
    shift(arr, kolDisk);
    shift(i, kolDisk);
    step++;
    return tower(kolDisk, arr[0], arr[1], arr[2]);
}

int main() {
    int kolDisk;
    cin >> kolDisk;
    int kol = tower(kolDisk, 1, 2, 3);
    cout << "Количество действий: " << kol << endl;
    return 0;
}*/

/*8. ver2*/
#include <iostream>
using namespace std;

int tower(int kolDisk, int one, int two, int three) {
    if(kolDisk == 0) return 1;
    cout << one << "->" << two << endl;
    tower(kolDisk - 1, one, three, two);
    tower(kolDisk - 1, two, one, three);
}

int main() {
    int kolDisk;
    cin >> kolDisk;
    int kol = tower(kolDisk, 1, 2, 3);
    cout << "Количество действий: " << kol << endl;
    return 0;
}