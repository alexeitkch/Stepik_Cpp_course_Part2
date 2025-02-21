// Lesson_5.1 ���������: ���������� � �������������
//

/*2.�������� ��������� Tovar (�������� ������, ������-�������������, ����).  
������� ������ �� 7 ��������� ���� Tovar. ��������� ������ �������, ������ �� � �������. 
���������� � ������ ������ �������� � ����� ������, 
� �������� ����������� ����� ��� ����������� ���������.
����� �������� �������� ������. 
�� ������� ��������� ������ �������, 
������������� � ���� ������ (������ ����� � ����� ������). 
� ����� � ����� ������ ��������� ������� ���� �� ������ �� ���� ������. 
������� ���� ����������� � ����� ������� ����� �����.
���� �� ������� �� ���� ������ ��� � ������, 
����� ������� �� ������� ����� "Error".
Sample Input:
������ �������� 1.58
����� ������� 1.9
������ �������� 2.5
������ ������� 3.2
������� �������� 2.1
������� ������ 4.5
���� ������ 3.1
��������
Sample Output:
������ �������� 1.58
������ �������� 2.5
������� �������� 2.1
2.06
*/
/*
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Tovar {
    char name[30];
    char madein[30];
    double price;
};
int main() {
    const int N = 7;
    Tovar arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].name >> arr[i].madein >> arr[i].price;
        //while (cin.get() != '\n');
    }
    char city[30];
    cin >> city;
    int k = 0;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(city, arr[i].madein) == 0) {
            cout << arr[i].name << " " << arr[i].madein << " " << arr[i].price << endl;
            k++;
            sum += arr[i].price;
        }   
    }
    if (k == 0) {
        cout << "Error" << endl;
    }
    else {
        cout << fixed << setprecision(2) << (double)sum/k << endl;
    }
    return 0;
}*/

/*3. ������� ��������� Student (�������, ���, ������, ������� � �����, ������� ����). 
�������� ������ �� 8 ��������� ���� Student. ��������� ������ �������, 
������ �� � �������. ���������� � ������ �������� �������� � ����� ������, 
� �������� ����������� ����� ��� ����������� ���������.
����� �������� �������� ������. 
������� ������ ���������� ���� ������ (������� ���� ������� ������ 8.0).  
���������� ������� ������� ���� ����������. 
���������� � ������ ��������� �������� ��������� � ����� ������, 
���� ���������� ����� ��������. ������� ���� �������� �� ������������. 
����� � ����� ������ ��������� ������� �������. 
�� ������ ���� ��������� �� ������ ����� ����� ���������� �����.
���� � ��������� ������ ��� ���������� (��� ������ ��� ����� ������), �� ��������� "Error".

Sample Input:
������ ������     S-11  21 6.7
�������� �����    G-11 23 8.6
�������   ������ S-11 18 9.2
��������� ����     S-11  22 8.4
������� �����  G-11 17 5.7
�������� ������� S-11 32 7.8
������� �������     S-11 30 8.7
��������� ����� G-11   17  9.8
S-11

Sample Output:
������� ������ S-11 18 9.2
��������� ���� S-11 22 8.4
������� ������� S-11 30 8.7
23.3
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Student {
    char surname[30];
    char name[30];
    char group[30];
    int age;
    double averageBall;
};
int main() {
    const int N = 8;
    Student arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].surname >> arr[i].name >> arr[i].group >> arr[i].age >> arr[i].averageBall;
    }
    char word[30];
    cin >> word;
    int k = 0;
    int ageSum = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(word, arr[i].group) == 0) {
            if (arr[i].averageBall > 8.0) {
                cout << arr[i].surname << " " << arr[i].name << " " << arr[i].group << " " << arr[i].age << " " << arr[i].averageBall << endl;
                ageSum += arr[i].age;
                k++;
            }
        }
    }
    if (k == 0)
        cout << "Error" << endl;
    else
        cout << fixed << setprecision(1) << (double)ageSum / k << endl;
    return 0;
}
