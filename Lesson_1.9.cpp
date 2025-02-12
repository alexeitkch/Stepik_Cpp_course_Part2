// Lesson_1.9 Тест
/*3.
#include <iostream>
using namespace std;
int main()
{
    int a = 20, b;
    int* ptr = &a;
    cout << ptr << endl;
    //значение по указателю присвоится b, 
    // а указатель увеличится потом на 1
    b = *ptr++;
    cout << ptr << endl;
    cout << "a = " << a << " b = " << b << endl;
}
*/

/*5.
#include <iostream>
using namespace std;
int main()
{
    double x = 3.5;
    double* p = &x;

    //*p = *p / 2;  //p = 000000A6B8DEF578 *p = 1.75
    //(*p)++;       //p = 00000096EEF7F9D8 *p = 4.5
    //*p = 4;       //p = 00000084864FF878 *p = 4
    //*p = *p % 2;  //expression must have integral or unscoped enum type (тип double не подходит под действие)

    cout << "p = " << p << " *p = " << *p << endl;
    return 0;
}
*/

/*6.
#include <iostream>
using namespace std;
int main()
{
    int a[] = { 1,3,7,9,10 };
    //int* ptr = a++; //expression must be a modifiable lvalue (a неизменяемая величина)
    //cout << *ptr;
    return 0;
}
*/

/*9.
#include <iostream>
using namespace std;
int main()
{
    const int N = 10;
    const int* const ptr = &N;

    //int b = *ptr++;//expression must be a modifiable lvalue (a неизменяемая величина) указатель константа
    //int c = (*ptr)++;//expression must be a modifiable lvalue (a неизменяемая величина) значение константа
    int d = *ptr + 1; //11
    int e = (*ptr) + N; //20
    
    cout << "ptr = " << ptr << " *ptr = " << *ptr << endl;
    cout << "d = " << d << " e = " << e << endl;
    return 0;
}
*/

/*12.*/
#include <iostream>
using namespace std;
int main()
{
    /*z - это двумерный массив, который интерпретируется как массив из массивов. 
    Т.е. z - это указатель на массив-строку с индексом 0. 
    z+2 - это указатель на массив-строку с индексом 2
    *(z+2) - это значение по этому указателю, т.е.  указатель на нулевой элемент строки с индексом 2
    *(z+2)+1 - указатель на первый элемент строки с индексом 2
    Когда разыменуем это выражение, получим значение элемента двумерного массива z[2][1]*/

    int z[4][2] = { 8,7,6,5,4,3,2,1 };
    cout << *(*(z + 2) + 1) << "\n"; //3
    return 0;
}