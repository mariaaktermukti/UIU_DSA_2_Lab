#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int memo[100][100];

int coinChangeMemo(int coins[], int n, int sum) {
    if (sum == 0) return 0;
    if (n == 0) return INT_MAX - 1;

    if (memo[n][sum] != -1)
        return memo[n][sum];

    if (coins[n-1] <= sum) {
        memo[n][sum] = min(
            1 + coinChangeMemo(coins, n, sum - coins[n-1]),
            coinChangeMemo(coins, n-1, sum)
        );
    } else {
        memo[n][sum] = coinChangeMemo(coins, n-1, sum);
    }

    return memo[n][sum];
}

int main() {
    int coins[] = {1,2,3,4};
    int sum = 4;
    int n = 4;

    memset(memo, -1, sizeof(memo));
    cout << coinChangeMemo(coins, n, sum);
}
