// Given an array of integers, count how many times each number appears.
// Input:
// [1, 2, 2, 3, 1, 4, 2]

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> freq;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    cout << "\nFrequency of each element:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
