#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> freq;
    cout<<"Enter a sentence: "<< endl;
    string sentence;
    getline(cin, sentence);

    string word;
    stringstream ss(sentence);
    while(ss>> word)
    {
        freq[word]++;
    }

    for(auto it: freq)
    {
        cout<< it.first<< " -> " << it.second<< endl;
    }

    return 0;
}