#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

pair<int,int> FindSecMax(int arr[],int left, int right)
{
    if(left==right)
        return {arr[left],INT_MIN};

    int mid=(left+right)/2;

    pair<int,int> left_ans= FindSecMax(arr,left,mid);
    pair<int,int> right_ans= FindSecMax(arr,mid+1,right);

    pair<int,int> result;

    if(left_ans.first >= right_ans.first)
    {
        result.first = left_ans.first;
        result.second = max(left_ans.second, right_ans.first);
    }
    else
    {
        result.first = right_ans.first;
        result.second = max(right_ans.second, left_ans.first);
    }

    return result;
}

pair<int,int> FindSecMin(int arr[],int left,int right)
{
    if(left==right)
        return {arr[left],INT_MAX};

    int mid=(left+right)/2;

    pair<int,int> left_ans = FindSecMin(arr, left, mid);
    pair<int,int> right_ans = FindSecMin(arr, mid + 1, right);

    pair<int,int> result;

    if(left_ans.first <= right_ans.first)
    {
        result.first = left_ans.first;
        result.second = min(left_ans.second, right_ans.first);
    }
    else
    {
        result.first = right_ans.first;
        result.second = min(right_ans.second, left_ans.first);
    }

    return result;
}

int main()
{
    int arr[]={5,4,-1,7,8};
    int len=sizeof(arr)/sizeof(arr[0]);

    pair<int,int> SecMax= FindSecMax(arr,0,len-1);
    pair<int,int> SecMin= FindSecMin(arr,0,len-1);

    cout<<"2nd max is : " << SecMax.second << endl;
    cout<<"2nd min is : " << SecMin.second << endl;

    return 0;
}
