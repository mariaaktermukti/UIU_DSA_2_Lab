#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l1 = {1, 3, 5};
    list<int> l2 = {2, 4, 6};

    l1.merge(l2);

    cout << "Merged List: ";
    for (int x : l1)
        cout << x << " ";
    cout << endl;

    return 0;
}
