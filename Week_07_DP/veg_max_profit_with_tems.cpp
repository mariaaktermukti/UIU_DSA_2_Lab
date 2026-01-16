#include <bits/stdc++.h>
using namespace std;

struct Vegetable
{
    char name[20];
    int weight;
    int buyPrice;
    int sellPrice;
    int profit;
};

void knapsack(int n, int W, Vegetable vegs[])
{
    int dp[101][1005];
    bool keep[101][1005];

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = 0;
            keep[i][w] = false;
        }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (vegs[i - 1].weight <= w)
            {
                int takeProfit = dp[i - 1][w - vegs[i - 1].weight] + vegs[i - 1].profit;
                if (takeProfit > dp[i - 1][w])
                {
                    dp[i][w] = takeProfit;
                    keep[i][w] = true;
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = W;
    vector<pair<string, int>> taken;
    for (int i = n; i >= 1; i--)
    {
        if (keep[i][w])
        {
            taken.push_back({vegs[i - 1].name, vegs[i - 1].weight});
            w -= vegs[i - 1].weight;
        }
    }
    reverse(taken.begin(), taken.end());

    for (auto &p : taken)
    {
        cout << p.first << " " << p.second << " kg\n";
    }
    cout << "Maximum profit = Tk. " << dp[n][W] << endl;
}

int main()
{
    int n, W;
    cin >> n >> W;

    Vegetable vegs[101];
    for (int i = 0; i < n; i++)
    {
        cin >> vegs[i].name >> vegs[i].weight >> vegs[i].buyPrice >> vegs[i].sellPrice;
        vegs[i].profit = vegs[i].sellPrice - vegs[i].buyPrice;
    }

    knapsack(n, W, vegs);

    return 0;
}
