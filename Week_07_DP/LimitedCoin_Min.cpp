#include <iostream>
#include <climits>
using namespace std;

int minCoinsLimited(int coins[], int supply[], int n, int T)
{
    int dp[10005]; 
    for (int j = 0; j <= T; j++)
        dp[j] = INT_MAX; 

    dp[0] = 0; 

    for (int i = 0; i < n; i++)
    {
        for (int j = T; j >= 0; j--)
        {
            for (int k = 1; k <= supply[i]; k++)
            {
                if (j - k * coins[i] >= 0 && dp[j - k * coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - k * coins[i]] + k);
                }
            }
        }
    }

    if (dp[T] == INT_MAX)
    {
        return -1;
    }  
    return dp[T];
}

int main()
{
    int n;
    cin >> n;

    int coins[100], supply[100];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
        
    for (int i = 0; i < n; i++)
    {
        cin >> supply[i];
    }
        
    int T;
    cin >> T;

    int ans = minCoinsLimited(coins, supply, n, T);

    if (ans == -1)
    {
        cout << "Impossible" << endl;
    }   
    else
    {
        cout << ans <<endl;
    }
        

    return 0;
}
