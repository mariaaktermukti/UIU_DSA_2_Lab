#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<string, int> m;

    m.emplace("TV",100);
    m.emplace("TV",100);
    m.emplace("TV",100);
    m.emplace("TV",100);

    m.erase(m.find("TV"));

    for(auto p:m)
    {
        cout<< p.first << " " << p.second<< endl;
    }

    cout<<"Count= " << m.count("TV") << endl; // count =3, total 4 bar celo, 1 bar erase korchi. akn 3 bar

    return 0;
}