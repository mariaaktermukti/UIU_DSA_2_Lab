#include<iostream>
#include<algorithm>
using namespace std;

int findMax(int arr[], int l, int h)
{
    if(l==h) return arr[l]; //base case

    int mid=(l+h)/2;

    int leftMax= findMax(arr,l,mid);
    int rightMax= findMax(arr,mid+1,h);

    return max(leftMax, rightMax);
}

int main()
{
    int arr[]={1,2,3,4,8,9,-2,-4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int total_len= n-1;

    cout<< "Max number is : " << findMax(arr,0,total_len) << endl;

}