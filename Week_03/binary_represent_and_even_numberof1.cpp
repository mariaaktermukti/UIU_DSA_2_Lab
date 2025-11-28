#include <iostream>
using namespace std;

int countOnes(int num) 
{
    int count = 0;
    while (num > 0) 
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int evenOnesCount(int arr[], int left, int right) 
{
    if (left == right) 
    {
        if (countOnes(arr[left]) % 2 == 0) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    }

    int mid = left + (right - left) / 2;

    int leftCount = evenOnesCount(arr, left, mid);
    int rightCount = evenOnesCount(arr, mid + 1, right);
    
    return leftCount + rightCount;
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int result = evenOnesCount(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}
