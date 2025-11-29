#include <iostream>
using namespace std;

int stairClimb(int n)
{
    if(n==0 || n==1) return 1;
    return stairClimb(n-1) + stairClimb(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << stairClimb(n);
    return 0;
}
