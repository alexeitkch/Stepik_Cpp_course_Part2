// Lesson_1.5
//

/*1.Двумерный массив целых чисел размерности 4 на 3 
заполнить случайными значениями от 0 до 10 
(начальное значение генератора случайных чисел  вводит пользователь). 
Распечатать массив в виде таблицы.  
После каждого элемента должен стоять знак табуляции.
С новой строки вывести количество нулевых элементов массива.
Использовать указатели при работе с двумерным массивом!*/
/*
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int ROW = 4;
    const int COL = 3;
    int arr[ROW][COL];
    int* ptr = arr[0];
    int sum = 0;
    //ввод исходного массива
    for (int i = 0; i < ROW * COL; i++, ptr++) {
        *ptr = rand() % 11;
    }
    //вывод таблицы исходного массива
    ptr = arr[0];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++, ptr++) {
            cout << *ptr << "\t";
            if (*ptr == 0)
                sum++;
        }
        cout << endl;
    }
    cout << sum << endl;
    return 0;
}
*/

/*2.*/
#include <iostream>
using namespace std;
int main() {
    int start;
    cin >> start;
    srand(start);
    const int ROW = 5;
    const int COL = 6;
    int arr[ROW][COL];
    int* ptr = arr[0];
    //ввод исходного массива
    for (int i = 0; i < ROW * COL; i++, ptr++) {
        *ptr = rand() % 11 - 3;
    }
    //вывод таблицы исходного массива
    ptr = arr[0];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++, ptr++) {
            cout << *ptr << "\t";
        }
        cout << endl;
    }
    //вывод элементов второй строки
    ptr = arr[0] + 1;
    for (int i = 0; i < COL - 1; i++, ptr += COL) {
        cout << *ptr << "\t";
    }
    cout << endl;
    return 0;
}