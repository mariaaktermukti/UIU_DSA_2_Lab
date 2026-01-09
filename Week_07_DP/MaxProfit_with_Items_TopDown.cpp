#include <iostream>
using namespace std;

int memo[100][100];

int knapsack(int wt[], int p[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (memo[n][W] != -1)
    {
        return memo[n][W];
    }
        
    if (wt[n - 1] <= W)
    {
        int include = p[n - 1] + knapsack(wt, p, n - 1, W - wt[n - 1]);
        int exclude = knapsack(wt, p, n - 1, W);
        memo[n][W] = max(include, exclude);
    }
    else
    {
        memo[n][W] = knapsack(wt, p, n - 1, W);
    }

    return memo[n][W];
}

void printSelectedItems(int wt[], int p[], int n, int W)
{
    cout << "Selected Items" << endl;

    while (n > 0 && W > 0) //backtracking
    {
        if (memo[n][W] == memo[n - 1][W]) //not take -> profit come from direct up
        {
            n = n - 1;
        }
        else // take item
        {
            cout << wt[n - 1] << "  " << p[n - 1] << endl;
            W = W - wt[n - 1]; 
            n = n - 1;
        }
    }
}

int main()
{
    int weight[] = {1, 3, 4, 5};
    int profit[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            memo[i][j] = -1;
        }
    }

    int maxProfit = knapsack(weight, profit, n, W);

    cout << "Maximum Profit = " << maxProfit << endl;
    printSelectedItems(weight, profit, n, W);

    return 0;
}


// // selectItem part e 
//         if (memo[n][W] == memo[n - 1][W]) 
//         {
//             n = n - 1;
//         }
//         else // take item
//         {
//             cout << wt[n - 1] << "  " << p[n - 1] << endl;
//             W = W - wt[n - 1]; 
//             n = n - 1;
//         }
// Selected items are found by comparing memo[n][W] with memo[n−1][W].
// If equal → item not taken, else → item taken and capacity reduced.