#include <iostream>
using namespace std;

bool isPower(int n, int x) 
{
    if(n == 1) return true; 

    if(n < 1 || x == 1 && n != 1) return false; 
     
    if(n % x != 0) return false;  
    
    return isPower(n / x, x);   
}

int main() 
{
    int n, x;
    cout << "Enter n and x: ";
    cin >> n >> x;

    if(isPower(n, x))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
