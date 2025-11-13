#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> m;

    m.emplace("TV",100);
    m.emplace("Laptop",140);
    m.emplace("Watch",100);
    m.emplace("computer",100);

    for(auto p:m)
    {
        cout<< p.first << " " << p.second<< endl;
    }

    return 0;
}