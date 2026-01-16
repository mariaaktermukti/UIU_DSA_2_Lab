#include <bits/stdc++.h>
using namespace std;

int countWaysDP(int sum, int coins[], int n, int dp[][1005])
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= coins[i - 1])
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

void printCombinations(int sum, int coins[], int n, vector<int> &comb, int i, int j)
{
    if (j == 0)
    {
        for (int x = 0; x < comb.size(); x++)
        {
            cout << comb[x] << " ";
        }
        cout << "\n";
        return;
    }
    if (i == 0)
        return;
    printCombinations(sum, coins, n, comb, i - 1, j);

    if (coins[i - 1] <= j)
    {
        comb.push_back(coins[i - 1]);
        printCombinations(sum, coins, n, comb, i, j - coins[i - 1]);
        comb.pop_back();
    }
}

int main()
{
    int n, sum;
    cin >> n;

    int coins[105];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cin >> sum;

    int dp[105][1005];

    int totalWays = countWaysDP(sum, coins, n, dp);
    cout << "Total ways to make sum " << sum << " = " << totalWays << "\n";

    cout << "All combinations:\n";
    vector<int> comb;
    printCombinations(sum, coins, n, comb, n, sum);

    return 0;
}
