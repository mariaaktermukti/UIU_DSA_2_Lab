#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;


bool isVowel(char ch)
{
    ch= tolower(ch);
    return (ch =='a'|| ch =='e'|| ch =='i'|| ch =='o'|| ch =='u');
}

int countVowels(string s, int left, int right)
{
    if(left==right)
    {
        if(isVowel(s[left]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int mid=(left+right)/2;

    int leftCount = countVowels(s, left, mid);
    int rightCount = countVowels(s, mid + 1, right);

    return leftCount+ rightCount;
    
}

int main()
{
    string str= "DivideAndConquerIsFun";
    int n= str.length();

    int totalVowels = countVowels(str,0,n-1);
    cout<< "Total vowel in the string : " << totalVowels << endl;
    return 0;
}
