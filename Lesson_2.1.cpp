// Lesson_2.1 Понятие функции

/*1.Напишите функцию, которая возвращает истину, 
если ее целочисленный аргумент - простое число, 
и ложь - если оно не является простым 
(простое число делится нацело только на 1 и на себя: 2,3,5,7 и т.д.). 
Напоминаю, что единица не являются простым числом!  
Отрицательные числа  и ноль не могут быть простыми, 
т.к. по определению простое число  является натуральным.*/
/*
#include<iostream>
using namespace std;

//variant_1 проверки на простое число
bool simple(int a) {
    if (a < 2)
        return false;
    for (int i = 2; i < a / 2 + 1; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}


//variant_2 проверки на простое число
bool simple(int a) {
    if (a < 2) 
        return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}


int main() {
    int x;
    cin >> x;
    if (simple(x)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}
*/


/*2.Напишите функцию, которая выводит на экран рамку из звездочек. 
В качестве параметров в функцию передаются ширина и высота рамки. 
После вывода рамки курсор должен перейти на новую строку.*/
/*
#include <iostream>
using namespace std;
void frame(int l, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            if (i == 0 || i == h - 1) {
                cout << '*';
            }
            else
                if (j == 0 || j == l - 1)
                    cout << '*';
                else
                    cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int l, h;
    cin >> l >> h;
    if (l <= 0 || h <= 0) return 1;
    frame(l, h);
    return 0;
}*/

/*3.Описать функцию, которая возводит x в степень y (где x и y – целые числа, y>0)
(raising to a power or exponentiation). 
Использовать эту функцию для вывода на консоль кубов чисел от 2 до 10.
*/
/*
#include <iostream>
using namespace std;
int exp(int, int);

int main() {
    for (int i = 2; i <= 10; i++) {
        cout << exp(i, 3) << " ";
    }
    cout << endl;
    return 0;
}

int exp(int x, int y) {
    int p = x;
    for (int i = 1; i < y; i++) {
        p *= x;
    }
    return p;
}*/

/*4.Написать  функцию largerOf, которая заменяет значение  
каждой из двух переменных типа double большим из них.
В методе main продемонстрировано использование этой функции: 
вводятся два вещественных числа в переменные x и y, затем идет
вызов функции и выводятся на консоль значения x и y после вызова.*/
/*
#include<iostream>
using namespace std;
#include <iomanip>
void largerOf(double* x, double* y) {
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}

int main() {
    double x, y;
    cin >> x >> y;
    largerOf(&x, &y);
    cout << fixed << setprecision(2) << x << " " << y;
    return 0;
}*/

/*5.Написать функцию usred, которая заменяет значения  
каждой из двух  вещественных переменных их средним арифметическим.
В образце кода показано использование этой функции. 
При выводе число выводится с одним десятичным знаком.*/
/*
#include<iostream>
using namespace std;
#include <iomanip>
void usred(double* x, double* y) {
    *x = (*x + *y) / 2;
    *y = *x;
}

int main() {
    double x, y;
    cin >> x >> y;
    usred(&x, &y);
    cout << fixed << setprecision(1) << x << " " << y;
    return 0;
}*/

/*7. Напишите функцию, которая вычисляет площадь круга и длину окружности.*/
/*
#include<iostream>
using namespace std;
#include <iomanip>
double circle(double r, double* h) {
    *h = 2 * 3.14 * r;
    return 3.14 * r * r;
}

int main() {
    double r, square, length;
    cin >> r;
    square = circle(r, &length);
    cout << fixed << setprecision(2) << square << " " << length;
    return 0;
}*/

/*8. Напишите функцию, которая для целого числа 
возвращает количество цифр в числе и процент четных цифр.
В функции main продемонстрируйте ее использование: 
вводится число, затем вызов функции, и вывод результатов через пробел. 
Проценты должны выводится с округлением до  целого числа и со знаком %.*/

#include <iostream>
#include <iomanip>
using namespace std;

int cntOfDig(int a, double* pr) {
    int x = abs(a);
    int cnt = 0;
    int cntev = 0;
     do {
        if ((x % 10) % 2 == 0)
            cntev++;
        x /= 10;
        cnt++;
     } while (x > 0);
    *pr = (double)cntev / cnt * 100;
    return cnt;
}

int main() {
    int a;
    double prcnt;
    cin >> a;
    int cnt = cntOfDig(a, &prcnt);
    cout << fixed << setprecision(0) << cnt << " " << prcnt << "%" << endl;
    return 0;
}