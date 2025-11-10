#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec={1,2,3,4,5};
    // vec.insert(vec.begin()+2,100); //1 2 100 3 4 5 

    vec.clear();

    for(int val:vec)
    {
        cout<< val << " ";
    }
    cout<< "Size= " << vec.size()<< endl; //after vec.clear-> size will be 0
    cout<< "Capacity= "<< vec.capacity()<< endl; // as size is 5, capacity always 5
    //cout<< endl;

    return 0;
}