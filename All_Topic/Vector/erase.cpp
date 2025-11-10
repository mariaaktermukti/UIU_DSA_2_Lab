#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec={1,2,3,4,5};

    // vec.erase(vec.begin()); //1st index er value remove hbe

    // vec.erase(vec.begin()+2); //begin 1st index ke point korbe initially, then +2 korle 3rd index ta remove hbe

    //if i erase a range->(v.begin() + start, v.begin() + end)
    vec.erase(vec.begin()+1, vec.begin()+3); 

    for(int val:vec)
    {
        cout<< val<< " ";
    }
    cout<< endl;
    return 0;
}