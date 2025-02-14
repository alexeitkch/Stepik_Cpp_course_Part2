// Lesson_4.3 ������� ���������� string.h
//

/*1. ������������ ������ ��� ������, 
������� �������� ����� �������� �����. 
������ �������� ������ ����� ��������� 
������� � ������������� �������� �������� �� ����� ������ ('\n').
����� �������� ����� �������� ������ ������ ������� ';'. 
����� ��������� ��� ����� � ���� ������ � ������� ��� ������ �� �������. 
���������: ��������� ��������������, ��� ������� ����� ����� ���-�� 
������������ � ����������, ������������ ��� ������ ������� �� ������� �� ������. 
����� ������ ������������ ��� � ���� ����� ������, � ����� ��� ��������!
Sample Input:
To be or ;not; to be?
tes;ting; is good
I like ;ham; more then eggs
Sample Output:nottingham
*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 100;
    char str[MAXLEN];
    char word[MAXLEN] = "";
    char* ptrs;
    char* ptrr;
    for (int i = 0; i < 3; i++) {
        fgets(str, MAXLEN, stdin);
        ptrs = strchr(str, ';');
        ptrr = strrchr(str, ';');
        strncat_s(word, ptrs + 1, ptrr - ptrs - 1);
    }
    puts(word);
    return 0;
}
