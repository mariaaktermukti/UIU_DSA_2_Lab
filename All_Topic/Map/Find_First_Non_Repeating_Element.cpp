#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> count;
    for (int x : arr)
        count[x]++;

    for (int x : arr)
    {
        if (count[x] == 1)
        {
            cout << "First non-repeating element: " << x << endl;
            return 0;
        }
    }

    cout << "No non-repeating element found.\n";
    return 0;
}
