#include <iostream>
using namespace std;

void findMinMax(int arr[], int n, int &minVal, int &maxVal)
{
    if (n == 1)
    {
        minVal = maxVal = arr[0];
        return;
    }

    findMinMax(arr, n - 1, minVal, maxVal);

    if (arr[n - 1] < minVal)
        minVal = arr[n - 1];
    if (arr[n - 1] > maxVal)
        maxVal = arr[n - 1];
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

    int minVal, maxVal;
    findMinMax(arr, n, minVal, maxVal);
    cout << maxVal << minVal << endl;

    return 0;
}
