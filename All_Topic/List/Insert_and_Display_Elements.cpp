#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> lst;
    int n;
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        lst.push_back(n);
    }

    cout << "List elements: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;
    return 0;
}
