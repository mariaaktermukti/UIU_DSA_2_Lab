#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
    long long S, N, M;
    cin >> S >> N >> M;

    long long total_food = S * M;
    long long shop_open_days = S - S / 7;  

    long long max_possible_food = shop_open_days * N;

    if(max_possible_food < total_food) 
    {
        cout << -1 << endl;  
    }
    else 
    {
        long long min_days = (total_food + N - 1) / N;
        cout << min_days << endl;
    }
}
