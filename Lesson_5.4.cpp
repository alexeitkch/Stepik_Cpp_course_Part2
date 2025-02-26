//  Lesson_5.4 Организация даных: стек, очередь, дек.
//
//  Created by Aleksey on 24.02.2025.
//

/*1. Напишите набор функций для работы с очередью.
Очередь представьте в виде односвязного списка:
Указатель  Head на начало очереди, указатель Tail - на ее конец.
В функции main() организовано тестирование работы очереди:
пользователь вводит 1, 2, 3, 4 или 5 для соответственно добавления
элемента в очередь, удаления элемента, чтения элемента из начала очереди,
печати и очистки очереди. Ввод любого другого числа означает окончание работы программы.
Если пользователь вводит 1, то далее через пробел он вводит число,
которое должно быть помещено в очередь.
Вывод содержимого очереди отделяется пробелами (пробел должен быть
и после последнего элемента).
Sample Input:
1 45 1 34 1 28 2 4 5 4 7
Sample Output:
Извлечено: 45
Очередь (с начала): 34 28
Очередь пуста
*/
/*
#include <iostream>
#include <Windows.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void push(int data, Node*& head, Node*& tail) {
    Node* knot = new Node;
    knot->data = data;
    knot->next = NULL;
    if (head == NULL) {
        head = knot;
        tail = knot;
    }
    else {//следующие узлы
        tail->next = knot;
        tail = knot;
    }
}
int pop(Node*& head, Node*& tail) {
    if (head == NULL) {
        tail = NULL;
        return 0;
    }
    int tmp = head->data;
    Node* knot = head;
    head = head->next;
    delete knot;
    return tmp;
}
int peek(Node* head) {
    if (head == NULL) return 0;
    return head->data;
}
void print(Node* head) {
    if (head == NULL) {
        cout << "Очередь пуста" << endl;
        return;
    }
    cout << "Очередь (с начала): ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void clear(Node*& head, Node*& tail) {
    Node* knot;
    while (head) {
        knot = head;
        head = head->next;
        delete knot;
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* Tail = NULL, * Head = NULL;
    int choice;
    int number;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> number;
            push(number, Head, Tail);
            break;
        case 2:
            cout << "Извлечено: " << pop(Head, Tail) << endl;
            break;
        case 3:
            cout << "Первый: " << peek(Head) << endl;
            break;
        case 4:
            print(Head);
            break;
        case 5:
            clear(Head, Tail);
            break;
        default:
            clear(Head, Tail);
            return 0;
        }
    }
}*/

/*2.В качестве дополнительного задания создайте набор функций, моделирующий дек. 
Протестируйте его работу в Visual Studio (или в другой IDE).  
Для реализации дека нужно создать двусвязный список 
(два элемента-указателя в структуре):
Должны быть реализованы следующие функции:
Добавление элемента справа (push_right) ;
Добавление элемента слева (push_left);
Извлечение элемента справа (pop_right);
Извлечение элемента слева (pop_left);
Чтение элемента справа без удаления (right);
Чтение элемента слева без удаления (left);
Просмотр (печать) дека слева направо (print);
Очистка дека, т.е. удаление всех элементов (clear).
*/

#include <iostream>
#include <Windows.h>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
//дек - добавление элемента справа
void push_right(int data, Node* &left, Node* &right) {
    Node* knot = new Node;
    knot->data = data;
    knot->next = NULL;
    knot->prev = right;
    if (left == NULL) {//если это первый узел
        left = knot;
        right = knot;
        return;
    }
    right->next = knot;
    right = knot;
}
//дек - добавление элемента слева
void push_left(int data, Node* &left, Node* &right) {
    Node* knot = new Node;
    knot->data = data;
    knot->next = left;
    if (left == NULL) {//если первый узел
        left = knot;
        right = knot;
        return;
    }
    left->prev = knot;
    left = knot;
}
//дек - извлечение элемента справа
int pop_right(Node* &left, Node* &right) {
    if (right == NULL && left == NULL) {
        cout << "дек пустой нечего извлекать" << endl;
        return 0;
    } else {
        int tmp = right->data;//сохраняем данные во временной переменной
        if (right->prev != NULL) {
            right = right->prev;//перенаправляем right на предыдущий элемент
            right->next = NULL;//обнуляем ссылку next
        } else {
            delete right;//удаляем старый right по ссылке next
            right = NULL;
            left = NULL;
        }
        return tmp;//возврат данных
    }
}
//дек - извлечение элемента слева
int pop_left(Node* &left, Node* &right) {
    if (right == NULL && left == NULL) {
        cout << "дек пустой нечего извлекать" << endl;
        return 0;
    } else {
        int tmp = left->data;//сохраняем данные во временной переменной
        if (left->next != NULL) {
            left = left->next;//перенаправляем left на следующий элемент
            left->prev = NULL;//обнуляем ссылку prev
        }
        else {
            delete left->prev;//удаляем старый left по ссылке prev
            right = NULL;
            left = NULL;
        }
        return tmp;//возврат данных
    }
}
//дек - значение первого элемента справа без извлечения
int right(Node* right) {
    if (right == NULL) return 0;
    return right->data;
}
//дек - значение первого элемента слева без извлечения
int left(Node* left) {
    if (left == NULL) return 0;
    return left->data;
}
void print(Node* left, Node* right) {
    if (left == NULL && right == NULL) {
        cout << "Очередь пуста" << endl;
        return;
    }   
    cout << "Дек (слева на право): ";
    Node* tmp = left;
    while (tmp) {
        cout << tmp->data << " ";
        //cout << "Узел: prev=" << tmp->prev << " data=" << tmp->data << " next=" << tmp->next << " addr=" << tmp << " left=" << left << " right=" << right << endl;
        tmp = tmp->next;
    }
    cout << endl;
}
void clear(Node* &left, Node* &right) {
    if (left != NULL) {
        int c = 0;
        while (left) {
            Node* tmp = left;
            left = left->next;
            delete tmp;
            c++;
        }
        right = NULL;
        cout << "Количество удаленных элементов: " << c << endl;
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* Left = NULL, * Right = NULL;
    int choice;
    int data;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> data;
            push_right(data, Left, Right);
            break;
        case 2:
            cin >> data;
            push_left(data, Left, Right);
            break;
        case 3:
            cout << "Извлечено справа: " << pop_right(Left, Right) << endl;
            break;
        case 4:
            cout << "Извлечено слева: " << pop_left(Left, Right) << endl;
            break;
        case 5:
            cout << "Первый справа: " << right(Right) << endl;
            break;
        case 6:
            cout << "Первый слева: " << left(Left) << endl;
            break;
        case 7://print
            print(Left, Right);
            break;
        case 8:
            clear(Left, Right);
            break;
        default:
            clear(Left, Right);
            return 0;
        }
    }
}
