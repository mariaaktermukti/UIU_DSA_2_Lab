#include <iostream>
#include <climits>
using namespace std;

int findSecondMinOnly(int arr[], int left, int right) 
{
    if(left == right)
    {
        return INT_MAX; 
    }

    if(right - left == 1) 
    {
        return max(arr[left], arr[right]);
    }

    int mid = left + (right - left)/2;

    int leftSecond = findSecondMinOnly(arr, left, mid);
    int rightSecond = findSecondMinOnly(arr, mid+1, right);

    int leftMin = arr[left], rightMin = arr[mid+1];

    for(int i = left; i <= mid; i++) 
    {
        leftMin = min(leftMin, arr[i]);
    }

    for(int i = mid+1; i <= right; i++) 
    {
        rightMin = min(rightMin, arr[i]);
    }


    if(leftMin < rightMin) 
    {
        return min(rightMin, leftSecond);
    } 
    else if(rightMin < leftMin) 
    {
        return min(leftMin, rightSecond);
    } 
    else 
    { 
        return min(leftSecond, rightSecond);
    }
}

int main() {
    int arr[] = {3, 1, 4, 9, 1, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int secondMin = findSecondMinOnly(arr, 0, n-1);
    cout << "Second minimum element = " << secondMin << endl;

    return 0;
}
