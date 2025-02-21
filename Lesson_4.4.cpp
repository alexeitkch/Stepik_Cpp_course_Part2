// Lesson_4.4 Строки в стиле С++
//

/*1.Пользователь вводит строку и символ. 
Удалить все появления  этого символа в строке. 
При решении использовать методы типа string.
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


/*2. Пользователь вводит строку без  пробелов, 
которая представляет собой имя файла с расширением. 
Нужно проверить, является ли этот файл текстовым 
(т.е. с расширением .txt). 
Если да, то выводится имя файла без расширения. 
Если нет, то выводится NO. Если же введенная строка 
не содержит точки, то выводится ERROR.
Замечание. Для поиска последнего символа с конца 
можно использовать метод rfind(). 
Его использование аналогично методу find().*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    //поиск индекса последней точки в имени файла
    int k = str.rfind('.');
    if (k == string::npos) {
        cout << "ERROR" << endl;
        return 0;
    }
    else {
        //проверка расширения txt
        k = str.find("txt", k + 1);
        if (k == string::npos)
            cout << "NO" << endl;
        else
            //вывод имени файла без расширения
            cout << str.substr(0, k - 1) << endl;
    }
    return 0;
}
