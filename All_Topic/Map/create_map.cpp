#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;

    m["TV"]=100;
    m["Laptop"]=200;
    m["HeadPhone"]=50;

    for(auto p:m)
    {
        cout<< p.first << " " << p.second<< endl;

    }
    return 0;
}