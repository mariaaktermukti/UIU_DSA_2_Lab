#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout << "Deque elements: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After popping: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    return 0;
}
