//
//  main.cpp
//  Lesson_4.5
//
//  Created by Aleksey on 17.02.2025.
//

/*1. Вводится строка, которая может содержать пробелы.
 Максимальная длина строки 20 символов (без учета нуль-терминатора).
 Подсчитать, сколько знаков арифметических операций содержит эта строка.
 Рассматриваются только знаки +, -, *, / и %.*/
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 20;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    int sum = 0;
    while(*ptr != '\0') {
        if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%')
            sum++;
        ptr++;
    }
    printf("%d\n", sum);
    return 0;
}*/

/*1.v2*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 20;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    char str1[] = "+-*/%";
    int sum = 0;
    while(*ptr != '\0') {
        for(int i = 0; i < strlen(str1); i++) {
            if(*ptr == str1[i])
                sum++;
        }
        ptr++;
    }
    printf("%d\n", sum);
    return 0;
}

/*2. Вводится строка, которая может содержать пробелы.
 Все символы-цифры, которые в ней встречаются, замените
 символом '0'.  Распечатайте преобразованную строку.
 Во всех задачах, где не уточняется размер строки,
 считайте его равным 128.
 Sample Input:
 I have 128$ and 25 cents
 Sample Output:
 I have 000$ and 00 cents*/
/*
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 128;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    while (*ptr != '\0') {
        if(atoi(ptr)) {
           if(*ptr != '+'
               && *ptr != '-'
               && *ptr != '*'
               && *ptr != '/'
               && *ptr != '%'
               && *ptr != ' ')
                *ptr = '0';
        }
        ptr++;
    }
    puts(str);
    return 0;
}*/

/*2.v2*/
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 128;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char str1[] = "0123456789";
    char* ptr = str;
    while (*ptr != '\0') {
        for(int i = 0; i < strlen(str1); i++){
            if(*ptr == str1[i])
                *ptr = '0';
        }
        ptr++;
    }
    puts(str);
    return 0;
}*/
