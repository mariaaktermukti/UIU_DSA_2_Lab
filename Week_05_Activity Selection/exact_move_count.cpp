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

    int moves = 0;

    while (!A.empty())
    {
        int X = A[0];

        vector<int> toRemove;

        for (int i = 0; i < A.size(); i++)
        {
            if (abs(A[i] - X) <= 1)
            {
                toRemove.push_back(i);
            }
        }
        int removeCount = min(2, (int)toRemove.size());

        cout << "Move " << moves + 1 << ": Choose X = " << X
             << ", remove elements: ";
        for (int i = 0; i < removeCount; i++)
        {
            cout << A[toRemove[i]] << " ";
        }
        cout << endl;

        for (int i = removeCount - 1; i >= 0; i--)
        {
            A.erase(A.begin() + toRemove[i]);
        }

        moves++;
    }

    cout << "\nTotal moves to empty the array: " << moves << endl;

    return 0;
}
