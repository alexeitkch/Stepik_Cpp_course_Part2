// Lesson_4.3 ‘ункции библиотеки string.h
//

/*1. ѕользователь вводит три строки, 
которые содержат части кодового слова. 
 ажда€ вводима€ строка может содержать 
пробелы и заканчиваетс€ символом перехода на новую строку ('\n').
„асти кодового слова выделены внутри строки знаками ';'. 
Ќужно соединить эти части в одну строку и вывести эту строку на консоль. 
«амечание: поскольку предполагаетс€, что кодовое слово будет как-то 
использовано в дальнейшем, недостаточно его просто вывести на консоль по част€м. 
Ќужно именно сформировать его в виде одной строки, а затем уже выводить!
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
