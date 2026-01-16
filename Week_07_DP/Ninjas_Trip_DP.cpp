#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> days(n);
        for (int i = 0; i < n; i++)
        {
            cin >> days[i];
        }

        vector<int> cost(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> cost[i];
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            int j = i;
            while (j < n && days[j] < days[i] + 1)
            {
                j++;
            }

            int cost1 = cost[0] + dp[j];

            j = i;
            while (j < n && days[j] < days[i] + 7)
            {
                j++;
            }

            int cost7 = cost[1] + dp[j];

            j = i;
            while (j < n && days[j] < days[i] + 30)
            {
                j++;
            }

            int cost30 = cost[2] + dp[j];

            dp[i] = min({cost1, cost7, cost30});
        }

        cout << dp[0] << endl;
    }

    return 0;
}
