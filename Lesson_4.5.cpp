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
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    const int MAXLEN = 20;
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    char* ptr = str;
    char str1[] = "+-* /%";
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
*/
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

// Lesson_4.5 Дополнительные задания по теме "Строки"

/*4.Пользователь вводит строку, которая состоит из слов, 
разделенных одним или несколькими пробелами. 
Пробелы могут быть также перед первым и после последнего слова. 
С новой строки он вводит символ.
Найдите и распечатайте все слова, которые начинаются на этот символ. 
Каждое слово выводится с новой строки.
Sample Input:
It’s    better  to be   safe  than   sorry
s
Sample Output:
safe
sorry*/
//for visual studio
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	char c;
	//ввод символа
	c = getchar();
	char *word, *next = NULL;
	word = strtok_s(str, " ", &next);
	while (word != NULL) {
		if (*word == c)
			puts(word);
		word = strtok_s(NULL, " ", &next);
	}
	return 0;
}*/
/*
//for stepik
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	char c;
	//ввод символа
	cin >> c;
	char* word;
	word = strtok(str, " ");
	while (word != NULL) {
		if (*word == c)
			cout << word << endl;
		word = strtok(NULL, " ");
	}
	return 0;
}*/

/*5. Пользователь вводит строку, которая состоит из слов, 
разделенных одним или несколькими пробелами. 
Удалите из строки второе слово. Все пробелы должны остаться.
Преобразованная строка выводится на консоль.
Sample Input:
You   can't  make an omelet without breaking a few eggs
Sample Output:
You     make an omelet without breaking a few eggs*/
//visual studio
/*
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	char tmp[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	strcpy_s(tmp, MAXLEN, str);
	char* word, *next = NULL;
	word = strtok_s(tmp, " ", &next);
	word = strtok_s(NULL, " ", &next);
	int len = strlen(word);
	char* s = strstr(str, word);
	if (s != NULL) {
		while (*s != '\0') {
			*s = *(s + len);
			s++;
		}
	}
	puts(str);
	return 0;
}*/
//stepik
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	char tmp[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	//копируем строку в tmp
	strcpy(tmp, str);
	char* word;
	word = strtok(tmp, " ");
	word = strtok(NULL, " ");
	int len = strlen(word);
	//поиск лексемы word
	char* s = strstr(str, word);
	if (s != NULL) {
		//сдвиг части строки влево
		while (*s != '\0') {
			*s = *(s + len);
			s++;
		}
	}
	puts(str);
	return 0;
}*/

/*6 Пользователь вводит строку, которая состоит из слов, 
разделенных одним или несколькими пробелами.
Распечатайте все слова-палиндромы, которые встречаются  в данной строке. 
Палиндромом называется слово или фраза, которые одинаково читаются слева 
направо и справа налево. Например: deed (подвиг), level (уровень), sagas (саги, сказания).
Все прописные буквы перед проверкой переведите в строчные. 
Для этого можно использовать функцию int tolower(int c), 
которая преобразует символ к нижнему регистру.
Sample Input:
His deed described in Sagas
Sample Output:
deed
sagas
*/
//Visual Studio version
/*
#include <iostream>
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	char* word, *next = NULL;
	word = strtok_s(str, " ", &next);
	while (word != NULL) {
		char bword[MAXLEN];
		strcpy_s(bword, word);
		//перевод прописных символов в строчные
		for (int i = 0; i < strlen(bword); i++) {
			bword[i] = tolower(bword[i]);
			word[i] = tolower(word[i]);
		}
		//переворачиваем слово
		for (int i = 0; i < strlen(bword) / 2; i++) {
			char tmp = bword[i];
			int a = (strlen(bword) / 2 + 1) - i;
			bword[i] = bword[a];
			bword[a] = tmp;
		}
		if(!strcmp(word, bword))
			cout << word << endl;
		word = strtok_s(NULL, " ", &next);
	}
	return 0;
}*/

//Stepik version
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	const int MAXLEN = 128;
	char str[MAXLEN];
	//ввод строки
	fgets(str, MAXLEN, stdin);
	char* word;
	word = strtok(str, " ");
	while (word != NULL) {
		char bword[MAXLEN];
		strcpy(bword, word);
		//перевод прописных символов в строчные
		for (int i = 0; i < strlen(bword); i++) {
			bword[i] = tolower(bword[i]);
			word[i] = tolower(word[i]);
		}
		//переворачиваем слово
		for (int i = 0; i < strlen(bword) / 2; i++) {
			char tmp = bword[i];
			int a = (strlen(bword) / 2 + 1) - i;
			bword[i] = bword[a];
			bword[a] = tmp;
		}
		if (!strcmp(word, bword))
			cout << word << endl;
		word = strtok(NULL, " ");
	}
	return 0;
}
