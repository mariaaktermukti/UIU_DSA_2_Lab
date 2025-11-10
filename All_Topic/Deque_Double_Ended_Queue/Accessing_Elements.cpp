#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq = {5, 10, 15, 20};

    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 20
    cout << "Size: " << dq.size() << endl;   // 4

    dq[1] = 100; 
    cout << "Modified deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;
}
