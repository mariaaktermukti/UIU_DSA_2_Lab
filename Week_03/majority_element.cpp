#include <iostream>
using namespace std;

int countInRange(int arr[], int x, int left, int right) 
{
    int count = 0;
    for(int i = left; i <= right; i++) 
    {
        if(arr[i] == x)
            count++;
    }
    return count;
}

int majorityElementRec(int arr[], int left, int right) 
{
    if(left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftMajor = majorityElementRec(arr, left, mid);
    int rightMajor = majorityElementRec(arr, mid + 1, right);

    if(leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countInRange(arr, leftMajor, left, right);
    int rightCount = countInRange(arr, rightMajor, left, right);

    if(leftCount > rightCount)
        return leftMajor;
    else
        return rightMajor;
}

int main() 
{
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int majority = majorityElementRec(arr, 0, n - 1);

    cout << "Majority element is: " << majority << endl;

    return 0;
}
