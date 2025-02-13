//
//  main.cpp
//  Lesson_4.2
//
//  Created by Aleksey on 12.02.2025.
//

/*
//удвоить каждый введенный пользователем символ в строке
#include <iostream>
using namespace std;
#include <string.h>
//функция вставляет символ c в строку str на место ptr
void insert(char* str, char c, char* ptr){
    char* q = str + strlen(str); // на последний символ ‘\0’
    while (q >= ptr) {//пока не сдвинем все символы после ptr (и его тоже)
        *(q + 1) = *q; //сдвиг символа вправо
        q--;//подвигаем указатель влево
    }
    *ptr = c; //вставка символа
}
int main(){
    const int MAXLEN = 128;
    char mystring[MAXLEN];
    char sim, *ptr;
    fgets(mystring,MAXLEN,stdin); //ввод строки с пробелами
    sim = getchar();
    ptr = mystring; //указатель - на начало строки
    while (*ptr != '\0'){ //пока не достигнут конец строки
        if (*ptr == sim) {
            insert(mystring, sim, ++ptr); //вставляем sim в след. позицию
        }
        ptr++; //переход к следующему символу
    }
    puts(mystring);
    return 0;
}*/

/*1. Введите строку (в ней возможны пробелы).
Максимальный размер строки - 100 символов.
Замените каждый символ «;»   на пару символов «.,»*/
/*
#include <iostream>
#include <string.h>
using namespace std;
void changeSim(char* s, char* p) {
    char* q = s + strlen(s);
    while (q >= p) {
        *(q + 1) = *q;
        q--;
    }
    *p = '.';
    *(p + 1) = ',';
}
int main() {
    const int MAXLEN = 100;
    char str[MAXLEN];
    char *ptr;
    fgets(str, MAXLEN, stdin);
    ptr = str;
    while (*ptr != '\0') {
        if (*ptr == ';') {
            changeSim(str, ptr);
        }
        ptr++;
    }
    puts(str);
    return 0;
}*/

/*2. Введите строку (в ней возможны пробелы).
 Максимальный размер строки - 100 символов.
 Замените каждую пару символов «.,» на  символ «;»
 (отдельно  стоящий символ «.» или «,» трогать не нужно).
 Hello.,. world.., By.,.,-by,
 Hello;. world.; By;;-by,*/
/*
#include <iostream>
#include <string.h>
using namespace std;
void replace(char* a, char* p) {
    //удаление точки перед запятой
    char* pt = p;
    while (*pt != '\0') {
        *pt = *(pt + 1);
        pt++;
    }
    //замена запятой на точку с запятой
    char* q = a + strlen(a);
    while (q >= p) {
        q--;
    }
    *p = ';';
}
int main() {
    const int MAXLEN = 100;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr == '.' && *(ptr + 1) == ',') {
            replace(str, ptr);
        }
        ptr++;
    }
    puts(str);
    return 0;
}*/

/*
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    for (int i = 0; i <= 255; i++) {
        char c = i;
        printf("Symbol:%c kode:%d\n", c, i);
    }
    return 0;
}
*/

/*3. Введите строку (возможно, с пробелами). 
Подсчитайте, сколько она содержит символов цифр  
и латинских букв (учитываются и прописные, и строчные). 
Выведите результаты через пробел.
Sample Input: 2+3=4- Error!
Sample Output: 3 5 */
/*
#include <iostream>
using namespace std;
int main() {
    //setlocale(LC_ALL, "rus");
    const int MAXLEN = 100;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    int snum = 0;
    int slat = 0;
    while (*ptr != '\0') {
        if (*ptr >= 48 && *ptr <= 57) {
            snum++;
        }
        if ((*ptr >= 65 && *ptr <= 90) || (*ptr >= 97 && *ptr <= 122)) {
            slat++;
        }
        ptr++;
    }
    printf("%d %d", snum, slat);
    return 0;
}*/

/*4.Напишите функцию  bool findend(char *s, char *t), 
которая возвращает true, если строка t присутствует 
в конце строки s, и false - в противном случае. 
Если длина строки t больше длины строки s, то результат false.
В функции main тестируется использование этой функции. 
Вводятся две строки и выводится Yes, если результат функции 
true, и No в противном случае.
Замечание. Можно использовать стандартную функцию 
определения длины строки (strlen).*/
/*
#include <iostream>
using namespace std;
bool findend(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    if (len1 < len2) return false;
    else {
        char* ptra = a;
        char* ptrb = b;
        while (*ptra != '\0') {
            if (*ptra == *ptrb) {
                ptra++;
                ptrb++;
                while (*ptrb != '\0') {
                    if (*ptra == *ptrb) {
                        ptra++;
                        ptrb++;
                    }
                    else return false;
                }
                return true;
            }
            ptra++;
        }
    }
    return false;
}
int main() {
    const int MAXLEN = 128;
    char s[MAXLEN];
    char t[MAXLEN];
    fgets(s, MAXLEN, stdin);
    fgets(t, MAXLEN, stdin);
    if (findend(s, t)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}*/

/*5. Написать свою функцию копирования строк:
void mystrcpy(char* dest, char* source);
Функция копирует содержимое строки source в начало строки dest 
(влючая нулевой байт). 
В функции main() демонстрируется работа этой функции: вводятся две строки, 
затем вторая строка копируется в первую, и они обе выводятся на консоль.
Sample Input:
    first
    second
Sample Output:
    second
    second */
/*
#include <iostream>
using namespace std;
void mystrcpy(char* dest, char* source) {
    char* ptrd = dest;
    char* ptrs = source;
    while (*ptrs != '\0') {
        *ptrd = *ptrs;
        ptrs++;
        ptrd++;
    }
    *ptrd = '\0';
}
int main() {
    const int MAXLEN = 128;
    char s[MAXLEN];
    char t[MAXLEN];
    fgets(s, MAXLEN, stdin);
    fgets(t, MAXLEN, stdin);
    mystrcpy(s, t);
    printf("%s%s", s, t);
    return 0;
}*/


/*char* strchr(const char* s, int c) – ищет в строке s 
первое вхождение символа c, начиная с начала строки. 
В случае успеха возвращает указатель на найденный символ, 
иначе – возвращает NULL.*/
/*
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    char mystring[] = "Lord 0f the Rings";
    char c = '0'; //будем искать
    char* ptr = strchr(mystring, c);
    puts(mystring);
    //разность указателей дает количество элементов массива между ними
    cout << "Моя прелесть на " << ptr - mystring + 1 << " месте\n";
    return 0;
}*/

