#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> lst = {10, 20, 30, 40, 50};
    int val;
    cout << "Enter value to delete: ";
    cin >> val;

    lst.remove(val);

    cout << "After deletion: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;
    return 0;
}
