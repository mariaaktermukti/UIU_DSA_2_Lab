#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec={1,2,3,4,5};
    // cout<<"vec.begin= "<< *(vec.begin()) << endl; //vec.begin= 1
    // cout<<"vec.end= "<< *(vec.end()) << endl; //vec.end= 0


    // vector<int>:: iterator it;
    // for(it=vec.begin();it!=vec.end();it++)
    // {
    //     cout<< *(it)<<" "; //1 2 3 4 5
    // }
    // cout<< endl;

    for(auto it = vec.rbegin(); it!=vec.rend();it++)
    {
        cout<<*(it)<< " "; //5 4 3 2 1 
    }
    cout<< endl;


    return 0;
}