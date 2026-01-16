#include <iostream>
#include <climits>
using namespace std;

int minCoins(int coins[], int n, int T) {
    int dp[10005];   // assuming T <= 10000

    for (int i = 0; i <= T; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[T] == INT_MAX)
        return -1;
    return dp[T];
}

int main() {
    int n;
    cin >> n;

    int coins[100];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int T;
    cin >> T;

    int ans = minCoins(coins, n, T);

    if (ans == -1)
        cout << "Impossible";
    else
        cout << ans;

    return 0;
}
