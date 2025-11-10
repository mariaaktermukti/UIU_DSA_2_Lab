#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> lst = {10, 10, 20, 20, 30, 30, 30, 40};
    lst.unique();

    cout << "After removing duplicates: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;
    return 0;
}
