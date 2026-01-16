#include <iostream>
#include <climits>
using namespace std;
int dp[10005];
int coinUsed[10005];

int minCoinsWithCombination(int coins[], int n, int T)
{

    for (int i = 0; i <= T; i++)
    {
        dp[i] = INT_MAX;
        coinUsed[i] = -1;
    }

    dp[0] = 0;

    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                    coinUsed[i] = coins[j];
                }
            }
        }
    }

    if (dp[T] == INT_MAX)
    {
        return -1;
    }

    cout << "Coins used: ";
    int temp = T;
    while (temp > 0)
    {
        cout << coinUsed[temp] << " ";
        temp -= coinUsed[temp];
    }
    cout << endl;

    return dp[T];
}

int main()
{
    int n;
    cin >> n;

    int coins[100];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int T;
    cin >> T;

    int ans = minCoinsWithCombination(coins, n, T);

    if (ans == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << "Minimum coins needed: " << ans << endl;
    }

    return 0;
}
