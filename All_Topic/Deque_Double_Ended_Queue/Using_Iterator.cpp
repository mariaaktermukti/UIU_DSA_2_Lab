#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<string> dq = {"apple", "banana", "cherry"};

    cout << "Deque using iterator: ";
    for (auto it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
