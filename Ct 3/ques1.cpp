// You are given two integer arrays cost[] and time[], each of size n.
// cost[i] represents the cost required to paint the i-th wall.

// time[i] represents the time required to paint the i-th wall.
// You are also given an integer T, which represents the exact total time required to paint walls.

// Your task is to paint any subset of walls such that the sum of painting times is exactly T.
// Among all such possible choices, return the minimum total cost.

// If it is not possible to achieve exactly T time, return -1.

// sample input:
// cost = [1, 3, 4]
// time = [1, 2, 3]
// T = 3

// output:
//  4

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int cost[] = {1, 3, 4};
    int time[] = {1, 2, 3};
    int n = 3;
    int T = 3;

    int dp[T + 1];

    dp[0] = 0;
    for (int t = 1; t <= T; t++)
    {
        dp[t] = INT_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        for (int t = T; t >= time[i]; t--)
        {
            if (dp[t - time[i]] != INT_MAX)
            {
                dp[t] = min(dp[t], dp[t - time[i]] + cost[i]);
            }
        }
    }

    if (dp[T] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[T] << endl;
    }

    return 0;
}
