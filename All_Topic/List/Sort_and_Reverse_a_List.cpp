#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int> lst = {5, 2, 8, 1, 9};

    lst.sort();    
    lst.reverse(); 

    cout << "Sorted & Reversed List: ";
    for(int x : lst) cout << x << " ";
    cout << endl;
    return 0;
}
