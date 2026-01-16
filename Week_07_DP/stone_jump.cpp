#include <bits/stdc++.h>
using namespace std;
int dp[200005];
bool isSpike[200005];

int minimumPenalty(int n, int P, int spikes[], int k)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        isSpike[i] = false;
    }

    for (int i = 0; i < k; i++)
    {
        isSpike[spikes[i]] = true;
    }

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int cost;
        if (isSpike[i])
        {
            cost = P;
        }
        else
        {
            cost = 0;
        }

        dp[i] = dp[i - 1] + cost;

        if (i - 2 >= 1)
        {
            if (dp[i - 2] + cost < dp[i])
            {
                dp[i] = dp[i - 2] + cost;
            }
        }
    }

    return dp[n];
}

int main()
{
    int n, k, P;
    cin >> n >> P;
    cin >> k;

    int spikes[200005];
    for (int i = 0; i < k; i++)
    {
        cin >> spikes[i];
    }

    int result = minimumPenalty(n, P, spikes, k);
    cout << result << endl;

    return 0;
}
