#include<iostream>
#include<algorithm>
using namespace std;

int crossSum(int arr[], int l, int mid, int h)
{
    int left_max= INT_MIN;
    int sum=0;

    for(int i=mid;i>=l;i--)
    {
        sum= sum+arr[i];

        if(sum> left_max)
        {
            left_max= sum;
        }
    }


    int right_max=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=h;i++)
    {
        sum= sum+ arr[i];

        if(sum>right_max)
        {
            right_max=sum;
        }
    }

    return left_max+ right_max;

}

int maxSubArraySum(int arr[],int l,int h)
{
    if(l==h)
    {
        return arr[l];
    }
    
    int mid=(l+h)/2;

    int left_sum= maxSubArraySum(arr,l,mid);
    int right_sum= maxSubArraySum(arr,mid+1,h);
    int cross_sum= crossSum(arr,l,mid,h);


    return max({left_sum, right_sum, cross_sum});
    
}

int main()
{
    int arr[]={5,4,-1,7,8};
    int len=sizeof(arr)/sizeof(arr[0]);

    cout<< "Maximum sub array sum is : " << maxSubArraySum(arr,0,len-1) << endl;
    return 0;
}