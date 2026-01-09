#include <iostream>
using namespace std;

int tab[1000][1000];

int knapsack_tab(int wt[], int p[], int n, int W)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                 tab[i][j] = 0; // Base case
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

// Backtracking to find selected items
void printSelectedItems(int wt[], int p[], int n, int W)
{
    cout << "Selected Items :\n";
    int i = n, j = W;

    while (i > 0 && j > 0)
    {
        if (tab[i][j] != tab[i - 1][j])
        {
            // Item i is included
            cout << wt[i - 1] << ", " << p[i - 1] << "\n";
            j =j- wt[i - 1]; // Reduce capacity
        }
        i--; // Move to previous item
    }
}

int main()
{
    int weight[] = {1, 3, 4, 5};
    int profit[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    int maxProfit = knapsack_tab(weight, profit, n, W);
    cout << "Maximum Profit = " << maxProfit << endl;

    printSelectedItems(weight, profit, n, W);

    return 0;
}
