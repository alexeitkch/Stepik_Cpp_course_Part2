// Lesson_4.4 ������ � ����� �++
//

/*1.������������ ������ ������ � ������. 
������� ��� ���������  ����� ������� � ������. 
��� ������� ������������ ������ ���� string.
Sample Input:
!ma!ma!! m!!yla ramy!!
!
Sample Output:
mama myla ramy*/
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    char c;
    getline(cin, str);
    cin >> c;
    int k = str.find(c);
    while (k != string::npos) {
        //cout << k << endl;
        str.erase(k, 1);
        //cout << str << endl;
        k = str.find(c);
    }
    cout << str << endl;
    return 0;
}*/


/*2. ������������ ������ ������ ���  ��������, 
������� ������������ ����� ��� ����� � �����������. 
����� ���������, �������� �� ���� ���� ��������� 
(�.�. � ����������� .txt). 
���� ��, �� ��������� ��� ����� ��� ����������. 
���� ���, �� ��������� NO. ���� �� ��������� ������ 
�� �������� �����, �� ��������� ERROR.
���������. ��� ������ ���������� ������� � ����� 
����� ������������ ����� rfind(). 
��� ������������� ���������� ������ find().*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    //����� ������� ��������� ����� � ����� �����
    int k = str.rfind('.');
    if (k == string::npos) {
        cout << "ERROR" << endl;
        return 0;
    }
    else {
        //�������� ���������� txt
        k = str.find("txt", k + 1);
        if (k == string::npos)
            cout << "NO" << endl;
        else
            //����� ����� ����� ��� ����������
            cout << str.substr(0, k - 1) << endl;
    }
    return 0;
}
