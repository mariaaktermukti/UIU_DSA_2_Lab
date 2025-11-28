#include <iostream>
#include <climits>
using namespace std;

pair<int,int> findSecondMin(int arr[], int left, int right) 
{
    if(left == right) 
    {
        return {arr[left], INT_MAX};
    }

    if(right - left == 1) 
    {
        if(arr[left] <= arr[right])
            return {arr[left], arr[right]};
        else
            return {arr[right], arr[left]};
    }

    int mid = left + (right - left)/2;

    pair<int,int> leftResult = findSecondMin(arr, left, mid);
    pair<int,int> rightResult = findSecondMin(arr, mid+1, right);

    int overallMin, overallSecondMin;

    if(leftResult.first < rightResult.first) {
        overallMin = leftResult.first;
        overallSecondMin = min(leftResult.second, rightResult.first);
    } else if(rightResult.first < leftResult.first) {
        overallMin = rightResult.first;
        overallSecondMin = min(rightResult.second, leftResult.first);
    } else { 
        overallMin = leftResult.first;
        overallSecondMin = min(leftResult.second, rightResult.second);
    }

    return {overallMin, overallSecondMin};
}

pair<int,int> findSecondMax(int arr[], int left, int right) {
    if(left == right) {
        return {arr[left], INT_MIN};
    }

    if(right - left == 1) {
        if(arr[left] >= arr[right])
            return {arr[left], arr[right]};
        else
            return {arr[right], arr[left]};
    }

    int mid = left + (right - left)/2;

    pair<int,int> leftResult = findSecondMax(arr, left, mid);
    pair<int,int> rightResult = findSecondMax(arr, mid+1, right);

    int overallMax, overallSecondMax;

    if(leftResult.first > rightResult.first) {
        overallMax = leftResult.first;
        overallSecondMax = max(leftResult.second, rightResult.first);
    } else if(rightResult.first > leftResult.first) {
        overallMax = rightResult.first;
        overallSecondMax = max(rightResult.second, leftResult.first);
    } else { 
        overallMax = leftResult.first;
        overallSecondMax = max(leftResult.second, rightResult.second);
    }

    return {overallMax, overallSecondMax};
}

int main() 
{
    int arr[] = {5,4,-1,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    pair<int,int> resultMin = findSecondMin(arr, 0, n-1);
    pair<int,int> resultMax = findSecondMax(arr, 0, n-1);

    cout << "Second minimum element = " << resultMin.second << endl;
    cout << "Second maximum element = " << resultMax.second << endl;

    return 0;
}
