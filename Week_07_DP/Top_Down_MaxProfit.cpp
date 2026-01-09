#include<bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int knapsack(int wt[], int p[], int n, int W)
{
    //base case
    if(n==0 || W==0)
    {
        return 0;
    }

    if(memo[n][W]!=-1)
    {
        return memo[n][W];
    }

    if(wt[n-1]<=W)
    {
        int include= knapsack(wt,p,n-1,W-wt[n-1]) + p[n-1];
        int exclude= knapsack(wt,p,n-1,W);
        memo[n][W]= max(include, exclude);
    }
    else
    {
        memo[n][W]= knapsack(wt,p,n-1,W);
    }

    return memo[n][W];
}

int main()
{
    int weight[]={1,3,4,5};
    int profit[]={1,4,5,7};
    int n=4;
    int W=7;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            memo[i][j]=-1;
        }
    }

    cout<< knapsack(weight, profit,n,W) << endl;
    return 0;
}