// Lesson_5.2 Особые виды структур
//
/*
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    union Mymix {
        int i;
        char ch;
    } myvar;
    //int a;
    cout << "Введите код: ";
    cin >> myvar.i;
    cin >> a;
    cout << "Ему соответствует символ: " << myvar.ch << endl;
    //cout << "Ему соответствует символ: " << (char)a << endl;
    return 0;
}*/

/*1. Пользователь вводит вещественное число, 
которое размещается в переменной типа double. 
Нужно вывести на консоль внутреннее представление 
всех байтов этого числа в шестнадцатеричной системе счисления. 
Байты отделять пробелами. 
Использовать объединения! 
Sample Input:
45.138
Sample Output:
8b 6c e7 fb a9 91 46 40
*/
//программа для просмотра внутренней структуры double числа
/*
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    union Mymix {
        double num;
        unsigned char u[sizeof(double)];
    } myvar;
    cin >> myvar.num;
    for (int i = 0; i < sizeof(double); i++) {
        //printf("%x ", myvar.u[i]);
        cout << hex << (int)myvar.u[i] << " ";
    }
    cout << endl;
    return 0;
}*/

#include <iostream>
using namespace std;
struct Weather {
    unsigned int windRate : 7;
    unsigned int humidity : 7;
    unsigned int pressure : 11;
    signed int temperature : 7;
};
void input(Weather& a) {
    int temp;
    cout << "Введите скорость ветра (м/с): ";
    cin >> temp;
    a.windRate = temp;
    cout << "Введите влажность воздуха (%): ";
    cin >> temp;
    a.humidity = temp;
    cout << "Введите атмосферное давление (мм рт. столба): ";
    cin >> temp;
    a.pressure = temp;
    cout << "Введите температуру (С): ";
    cin >> temp;
    a.temperature = temp;
}
void out(Weather a){
    cout << "Скорость ветра (м/с): " << a.windRate << " м/с" << endl;
    cout << "Влажность воздуха (%): " << a.humidity << " %" << endl;
    cout << "Атмосферное давление (мм рт. столба): " << a.pressure << " мм.рт.ст" << endl;
    cout << "Температура (грд.С): " << a.temperature << " С" << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Размер структуры: " << sizeof(Weather) << endl;
    Weather pogoda;
    input(pogoda);
    cout << endl;
    out(pogoda);
    return 0;
}
