#include <iostream>
#include <algorithm>
using namespace std;

int crossSum(int arr[], int l, int mid, int h)
{
    int left_min = INT_MAX;
    int sum = 0;

    for (int i = mid; i >= l; i--)
    {
        sum = sum + arr[i];

        if (sum < left_min)
        {
            left_min = sum;
        }
    }

    int right_min= INT_MAX;
    sum=0;
    for (int i = mid+1; i<=h; i++)
    {
        sum = sum + arr[i];

        if (sum < right_min)
        {
            right_min = sum;
        }
    }

    return left_min+ right_min;
}

int MinSubarraySum(int arr[], int l, int h)
{
    if (l == h)
    {
        return arr[l];
    }

    int mid=(l+h)/2;

    int left_half = MinSubarraySum(arr, l, mid);
    int right_half = MinSubarraySum(arr, mid + 1, h);
    int cross_sum = crossSum(arr, l, mid, h);

    return min({left_half, right_half, cross_sum});
}

int main()
{
    int arr[] = {5, 4, -1, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum subarray sum is : " << MinSubarraySum(arr, 0, len - 1) << endl;
}