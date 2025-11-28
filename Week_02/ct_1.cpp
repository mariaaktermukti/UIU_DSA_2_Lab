//S(n)=3^0+3^2+3^4+3^6+…(first n terms)
//Compute the sum of the first n terms of the 
//series using two different approaches: Recursive Approach

#include <iostream>
#include <cmath>
using namespace std;

int sumSeries1(int n) {
    if(n == 1) return 1;             
    return pow(3, 2*(n-1)) + sumSeries1(n-1);
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << "Sum = " << sumSeries1(n) << endl;
    return 0;
}
