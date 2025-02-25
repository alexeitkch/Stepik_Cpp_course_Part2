//
//  main.cpp
//  Lesson_5.4
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

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(int data, Node* &head, Node* &tail) {
    Node* knot = new Node;
    knot->data = data;
    knot->next = NULL;
    if(head == NULL) {
        head = knot;
        tail = knot;
    }
    else {//следующие узлы
        tail->next = knot;
        tail = knot;
    }
}
int pop(Node* &head, Node* &tail) {
    if(head == NULL) {
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
    if(head == NULL) return 0;
    return head->data;
}
void print(Node* head) {
    if(head == NULL) {
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
void clear(Node* &head, Node* &tail) {
    Node* knot;
    while (head) {
        knot = head;
        head = head->next;
        delete knot;
    }
}
int main() {
    Node  *Tail=NULL, *Head=NULL;
    int choice;
    int number;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> number;
                push(number,Head, Tail);
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
                clear(Head,Tail);
                break;
            default:
                clear(Head,Tail);
                return 0;
        }
    }
}
