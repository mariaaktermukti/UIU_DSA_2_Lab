#include<iostream>
#include<algorithm>
using namespace std;

int FindMin(int arr[], int l, int h)
{
    if(l==h) return arr[l];  // base case

    int mid=(l+h)/2;

    int leftMin= FindMin(arr,l,mid);
    int rightMin= FindMin(arr,mid+1,h);

    return min(leftMin,rightMin);
}

int main()
{
    int arr[]={1,2,6,8,3,6,-1,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int total_len= n-1;

    cout<< "Min number is : " << FindMin(arr,0,total_len) << endl;
    return 0;
}