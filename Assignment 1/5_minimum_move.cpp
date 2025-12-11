#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter the array elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int maxValue = *max_element(A.begin(), A.end());

    vector<int> freq(maxValue + 2, 0);

    for (int val : A)
    {
        freq[val]++;
    }

    int moves = 0;

    for (int i = 0; i <= maxValue; i++)
    {
        int f = freq[i];

        moves += f / 2;

        if (f % 2 == 1)
            moves += 1;
    }

    cout << "Minimum moves to empty the array: " << moves << endl;

    return 0;
}
