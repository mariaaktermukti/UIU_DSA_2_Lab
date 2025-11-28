#include<iostream>
#include<algorithm>
using namespace std;

int EvenCount(int arr[], int l, int h)
{
    if(l==h) //base case
    {
        if(arr[l]% 2==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int mid=(l+h)/2;

    int leftCount=EvenCount(arr,l,mid);
    int rightCount=EvenCount(arr,mid+1,h);

    return leftCount + rightCount;


}

int main()
{
    int arr[]={1,2,6,8,3,6,-1,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int total_len= n-1;

    cout <<"Total Even count is : " << EvenCount(arr,0,total_len) << endl;

    return 0;
}