#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin>> n;
    // vector<int> v(n);
    // for(int i=0;i<n;i++)
    // {
    //     cin>> v[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     cout<< v[i] << endl;
    // }

    int n;
    cin>> n;
    vector<string> s(n);
    for(int i;i<n;i++)
    {
        cin>> s[i]; 
        // getline(cin,v[i])-> space soho string input nite gele
    }

    for(int i=0;i<n;i++)
    {
        cout<< s[i] << endl;
    }

    return 0;
}