#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<char> vec={'a','e','i','o'};
    // cout<< "Size= "<< vec.size()<< endl;
    // for(int i : vec)
    // {
    //     cout<< char(i) << endl;
    // }

    // make an empty vector
    //  vector<int> vec;
    //  cout<< "Size= " << vec.size() << endl; //output 0

    // push_back
    // vector<int> vec;
    // cout << "Size= " << vec.size() << endl;

    // vec.push_back(10);
    // vec.push_back(20);
    // vec.push_back(30);
    // cout << "After push back size is now= " << vec.size() << endl;

    // for (int i : vec)
    // {
    //     cout << i << endl;
    // }

    // pop_back
    // vector<int> vec;
    // cout << "Size= " << vec.size() << endl;

    // vec.push_back(10);
    // vec.push_back(20);
    // vec.push_back(30);

    // cout << "After push back size is now= " << vec.size() << endl;
    // vec.pop_back(); //delete 30

    // for (int i : vec)
    // {
    //     cout << i << endl;
    // }


    //front and back
    vector<int> vec;
    cout << "Size= " << vec.size() << endl;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << "After push back size is now= " << vec.size() << endl;
    vec.front();
    cout<< "Front value= " <<vec.front() << endl;
    vec.back();
    cout<< "Back value= " <<vec.back() << endl;

    for (int i : vec)
    {
        cout << i << endl;
    }

    return 0;
}