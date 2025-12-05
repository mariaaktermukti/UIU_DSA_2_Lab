#include <iostream>
using namespace std;

int main()
{
    long long sticks, diamonds;
    cin >> sticks >> diamonds;

    long long total_tools = 0;

    while (sticks > 0 && diamonds > 0)
    {
        if (sticks >= 2 && diamonds >= 1)
        {
            sticks -= 2;
            diamonds -= 1;
        }
        else if (sticks >= 1 && diamonds >= 2)
        {
            sticks -= 1;
            diamonds -= 2;
        }
        else
        {
            break;
        }
        total_tools++;
    }

    cout << total_tools << endl;
}
