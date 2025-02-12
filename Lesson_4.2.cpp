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
    char *ptr = str;
    while(*ptr != '\0') {
        if(*ptr == '.' && *(ptr + 1) == ',') {
            replace(str, ptr);
        }
        ptr++;
    }
    puts(str);
    return 0;
}
