//problem link:  https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= nums[i]; // XOR operation
    }

    cout << ans << endl;

    return 0;
}
