// Lesson_2.3 Ссылки
/*1. Напишите функцию, которая в целом неотрицательном числе  
переставляет цифры в обратном порядке. Т.е., например, 
число 123 превращает в 321, а число 4012 - в число 2104. */
/*
#include<iostream>
using namespace std;
//прототип
void transform(int&);

int main() {
	int a;
	cin >> a;
	transform(a);
	cout << a;
	return 0;
}

//функция переставляющая цифры
void transform(int& x) {
	int res = 0;
	while (x != 0) {
		res *= 10;
		int a = x % 10;
		x = (x - a) / 10;
		res += a;
	}
	x = res;
}
*/

/*2. Напишите функцию, которая определяет площадь поверхности и объем 
прямоугольного параллелепипеда.
В функции main имеется заготовка с вызовом этой функции. 
Вводятся длины трех сторон параллелепипеда, затем вызывается 
функция с именем  parallelepiped (которую и нужно реализовать), 
и после вызова выводятся на консоль площадь поверхности и объем 
параллелепипеда через пробел . */

#include<iostream>
using namespace std;
#include <iomanip>
//прототип
double parallelepiped(double, double, double, double&);

int main() {
	double a, b, c, square, volume;
	cin >> a >> b >> c;
	square = parallelepiped(a, b, c, volume);
	cout << fixed << setprecision(2) << square << " " << volume;
	return 0;
}
//функция вычисления площади поверхности и объема пр. параллелепипеда
double parallelepiped(double a, double b, double c, double& v) {
	v = a * b * c;
	return (a * b + b * c + c * a) * 2;
}