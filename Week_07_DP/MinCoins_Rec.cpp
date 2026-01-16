#include <iostream>
#include <climits>
using namespace std;

int coinChangeRec(int coins[], int n, int sum) {
    if (sum == 0) return 0;
    if (n == 0) return INT_MAX - 1;

    if (coins[n-1] <= sum) {
        return min(
            1 + coinChangeRec(coins, n, sum - coins[n-1]),
            coinChangeRec(coins, n-1, sum)
        );
    } else {
        return coinChangeRec(coins, n-1, sum);
    }
}

int main() {
    int coins[] = {1,2,3,4};
    int sum = 4;
    int n = 4;

    cout << coinChangeRec(coins, n, sum);
}

