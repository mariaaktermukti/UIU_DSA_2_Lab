#include <bits/stdc++.h>
using namespace std;

int tab[1000][1000];

int knapsack_Tabulation(int wt[], int p[], int n, int W)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                tab[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                tab[i][j] = max(p[i - 1] + tab[i - 1][j - wt[i - 1]], tab[i - 1][j]);
            }
            else
            {
                tab[i][j] = tab[i - 1][j];
            }
        }
    }
    return tab[n][W];
}
int main()
{
    int weight[] = {1, 3, 4, 5};
    int profit[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    cout << knapsack_Tabulation(weight, profit, n, W) << endl;
    return 0;
}