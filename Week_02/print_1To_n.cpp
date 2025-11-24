#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n == 1) return 1;        // base case
    return n + sum(n - 1);       // recursive call
}

int main() {
    int n;
    cout << "Enter the value of n : " ;
    cin >> n;
    cout << "Sum of 1 to n : " << sum(n) << endl;
}
