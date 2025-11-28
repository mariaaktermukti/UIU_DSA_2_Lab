#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


void merge(pair<int, int> arr[], int left, int mid, int right, int count[]) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;


    pair<int, int> L[n1];
    pair<int, int> R[n2];
    
    for(int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++) 
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    int rightCount = 0; 

    while(i < n1 && j < n2) 
    {
        if(L[i].first > R[j].first) 
        { 
            rightCount++;
            arr[k++] = R[j++]; 
        } 
        else 
        {
            count[L[i].second] += rightCount;
            arr[k++] = L[i++]; 
        }
    }

    while(i < n1) 
    {
        count[L[i].second] += rightCount;
        arr[k++] = L[i++];
    }
    
    while(j < n2) 
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(pair<int, int> arr[], int left, int right, int count[]) 
{
    if(left >= right) return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

void countSmallerElements(int nums[], int n, int result[]) 
{
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++) {
        arr[i].first = nums[i]; 
        arr[i].second = i;      
        result[i] = 0;       
    }
    mergeSort(arr, 0, n - 1, result);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[n];

    countSmallerElements(nums, n, result);

    cout << "Count of smaller elements to the right: ";
    for(int i = 0; i < n; i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}