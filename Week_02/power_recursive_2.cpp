#include <iostream>
#include <cmath>
using namespace std;

int sumSeries(int n) 
{
    if(n == 1) return 1;                
    return pow(4, 3*(n-1)) + sumSeries(n-1);
}

int main() 
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Sum = " << sumSeries(n) << endl;
    return 0;
}
