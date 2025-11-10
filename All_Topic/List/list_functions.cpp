#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>l;

    l.push_back(10);
    l.push_back(20);
    l.push_front(30);
    l.push_front(40);


    l.pop_back();
    l.pop_front();

    for(int val:l)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}