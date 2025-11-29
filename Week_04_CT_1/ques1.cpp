#include <iostream>
#include <algorithm>
using namespace std;

int crossSum(int arr[], int l, int mid, int h)
{
    int LeftMax = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= l; i--)
    {
        sum = sum + arr[i];

        if (sum > LeftMax)
        {
            LeftMax = sum;
        }
    }

    int RightMax = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= h; i++)
    {
        sum = sum + arr[i];

        if (sum > RightMax)
        {
            RightMax = sum;
        }
    }

    return LeftMax + RightMax;
}

int MaxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
    {
        return arr[l];
    }

    int mid = (l+h)/2;

    int left_sum = MaxSubArraySum(arr, l, mid);
    int right_sum = MaxSubArraySum(arr, mid + 1, h);
    int cross_sum = crossSum(arr, l, mid, h);

    return max({left_sum, right_sum, cross_sum});
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    // int arr[]={1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Largest Sum is : " << MaxSubArraySum(arr,0,len-1) << endl;
    return 0;
}