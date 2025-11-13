#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;

    m["TV"]=100;
    m["Laptop"]=200;
    m["Laptop"]=20;
    m["Laptop"]=230;
    m["HeadPhone"]=50;

    //insert function
    m.insert({"Camera",25});

    m.erase("TV");

    for(auto p:m)
    {
        cout<< p.first << " " << p.second<< endl;
    }

    if(m.find("Camera")!= m.end())
    {
        cout<< "Found" << endl;
    }
    else{
        cout<< "Not found" << endl;
    }

    cout<<"Count= " << m.count("Laptop") << endl;

    cout<<"Count key = " << m["Laptop"] << endl; //key value return korbe

    //erase
    return 0;
}