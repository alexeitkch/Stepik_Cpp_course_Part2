// Lesson_5.2 ������ ���� ��������
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
    cout << "������� ���: ";
    cin >> myvar.i;
    cin >> a;
    cout << "��� ������������� ������: " << myvar.ch << endl;
    //cout << "��� ������������� ������: " << (char)a << endl;
    return 0;
}*/

/*1. ������������ ������ ������������ �����, 
������� ����������� � ���������� ���� double. 
����� ������� �� ������� ���������� ������������� 
���� ������ ����� ����� � ����������������� ������� ���������. 
����� �������� ���������. 
������������ �����������! 
Sample Input:
45.138
Sample Output:
8b 6c e7 fb a9 91 46 40
*/
//��������� ��� ��������� ���������� ��������� double �����
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
    cout << "������� �������� ����� (�/�): ";
    cin >> temp;
    a.windRate = temp;
    cout << "������� ��������� ������� (%): ";
    cin >> temp;
    a.humidity = temp;
    cout << "������� ����������� �������� (�� ��. ������): ";
    cin >> temp;
    a.pressure = temp;
    cout << "������� ����������� (�): ";
    cin >> temp;
    a.temperature = temp;
}
void out(Weather a){
    cout << "�������� ����� (�/�): " << a.windRate << " �/�" << endl;
    cout << "��������� ������� (%): " << a.humidity << " %" << endl;
    cout << "����������� �������� (�� ��. ������): " << a.pressure << " ��.��.��" << endl;
    cout << "����������� (���.�): " << a.temperature << " �" << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    cout << "������ ���������: " << sizeof(Weather) << endl;
    Weather pogoda;
    input(pogoda);
    cout << endl;
    out(pogoda);
    return 0;
}