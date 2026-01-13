#include <iostream>
using namespace std;

int main()
{

    int V, E;
    cin >> V >> E;

    int g[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g[i][j] = -1;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }

    bool visited[V] = {false};

    visited[0] = true;
    int minCost = 0;

    for (int cnt = 0; cnt < V - 1; cnt++)
    {

        int x = -1, y = -1, mn = 1e9;

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!visited[j] && g[i][j] != -1 && g[i][j] < mn)
                    {
                        mn = g[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = true;
        minCost += mn;

        cout << x << " " << y << endl;
    }

    cout << minCost << endl;

    return 0;
}
