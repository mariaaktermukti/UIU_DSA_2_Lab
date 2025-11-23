#include <iostream>
using namespace std;

void swap_by_Val(int x, int y)
{

    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_by_Ref(int &x, int &y)
{

    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{

    int a = 5, b = 8;
    swap_by_Val(a, b);
    cout << "pass by value " << a << " " << b << endl;
    swap_by_Ref(a, b);
    cout << "pass by reference " << a << " " << b << endl;
}
