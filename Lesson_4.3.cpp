//
//  main.cpp
//  Lesson_4.3
//
//  Created by Aleksey on 15.02.2025.
//

/*2. Пользователь вводит строку,  состоящую из слов,
 разделенных одним или несколькими пробелами.
 Пробелы могут быть также в начале и в конце слова.
 Сформируйте новую строку, в которой слова исходной
 строки разделены ровно одним пробелом.
 Пробелы в начале и в конце строки тоже должны быть удалены.
 Для проверки этого выведите строку, обрамленную "палочками".
 Sample Input:
    Hello,     world!      Bye-bye,   sweet  home!
 Sample Output:
 |Hello, world! Bye-bye, sweet home!|*/
/*
#include <iostream>
using namespace std;
int main() {
    const int MAXLEN = 128;
    char source[MAXLEN];
    char result[MAXLEN] = "|";
    char* ptr;
    fgets(source, MAXLEN, stdin);
    ptr = strtok(source, " ");
    while (ptr != NULL) {
        strcat(result, ptr);
        strcat(result, " ");
        ptr = strtok(NULL, " ");
    }
    ptr = strrchr(result, ' ');
    *(ptr - 2) = '|';
    puts(result);
    return 0;
}*/

/*3.Пользователь вводит количество своих друзей, и данные о них.
 Для каждого человека указывается фамилия и дата рождения
 (в виде строк).
 Нужно соединить данные о человеке в одну строку,
 которая занимает ровно столько памяти, сколько необходимо.
 Формируется массив указателей на начала строк, как это было
 показано в предыдущем примере.
 Затем вводится фамилия. Нужно отыскать запись с этой фамилией
 (для простоты предположите, что однофамильцев не будет).
 Если запись найдена, то она выводится полностью (фамилия и дата рождения).
 Если человека с такой фамилией нет, то выводится "No".
 В идеале нужно отсортировать список, а затем использовать бинарный поиск.
 Но решение с линейным поиском в неотсортированном массиве тоже подойдет.
 Sample Input 1:
 4
 Иванов    25.06.2000
 Петров  06.03.2001
 Жук   17.05.2000
 Андреева   20.11.2002
 Жук
 Sample Output 1:
 Жук 17.05.2000*/

#include <iostream>
using namespace std;
void show(char** spisok, int cnt) {
    cout << endl;
    for(int i = 0; i < cnt; i++) {
        cout << spisok[i] << endl;
    }
    cout << endl;
}
void sort(char** spisok, int cnt) {
    for(int k = 0; k < cnt - 1; k++) {
        //индекс мин строки
        int min = k;
        for(int i = k + 1; i < cnt; i++) {
            //сравнение строк в цикле
            if(strcmp(spisok[i], spisok[min]) < 0) min = i;
        }
        //перестрановка указателей
        char* temp = spisok[k];
        spisok[k] = spisok[min];
        spisok[min] = temp;
    }
}
void seek(char** spisok, int cnt, char* ffam) {
    sort(spisok, cnt);
    int seeki = -1;
    //бинарный поиск
    int low = 0, up = cnt - 1, middle;
    char* tmp = new char[cnt];
    do {
        middle = (low + up) / 2;
        strcpy(tmp, spisok[middle]);
        if(strcmp(strtok(tmp," "), ffam) == 0) {
            seeki = middle;
            break;
        }
        if(strcmp(tmp, ffam) > 0) up = middle - 1;
        if(strcmp(tmp, ffam) < 0) low = middle + 1;
    } while (low <= up);
    delete[] tmp;
    tmp = NULL;
    /*
    //линейный поиск
    for(int i = 0; i < cnt; i++) {
        if(strcmp(strtok(spisok[i]," "), ffam) == 0)
            seeki = i;
    }*/
    if(seeki < 0)
        cout << "No" << endl;
    else
        cout << spisok[seeki] << endl;
}
int main() {
    const int MAXLEN = 128;
    //ввод количества записей
    int cnt;
    cin >> cnt;
    char** spisok = new char*[cnt];
    char fam[MAXLEN], data[MAXLEN];
    for(int i = 0; i < cnt; i++) {
        cin >> fam;
        cin >> data;
        int len = (int)(strlen(fam) + strlen(data) + 2);
        spisok[i] = new char[len];
        strcat(strcat(strcpy(spisok[i], fam), " "), data);
    }
    
    //ввод фамилии для поиска
    char ffam[MAXLEN];
    cin >> ffam;
    seek(spisok, cnt, ffam);
    //show(spisok, cnt);
    //sort(spisok, cnt);
    //show(spisok, cnt);
    return 0;
}
