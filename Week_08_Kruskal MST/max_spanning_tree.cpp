#include <bits/stdc++.h>
using namespace std;

int parent[10005];
int rankArr[10005];

int Find(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }     
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v)
{
    int rootU = Find(u);
    int rootV = Find(v);
    if (rootU == rootV)
    {
        return;
    }
        

    if (rankArr[rootU] > rankArr[rootV])
    {
        parent[rootV] = rootU;
        rankArr[rootU] += rankArr[rootV];
    }
    else
    {
        parent[rootU] = rootV;
        rankArr[rootV] += rankArr[rootU];
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    for (int i = 1; i <= V; i++)
    {
        parent[i] = -1;
        rankArr[i] = 1;
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    int totalWeight = 0;
    int cnt = 0;

    for (auto e : edges)
    {
        int w = e[0];
        int u = e[1];
        int v = e[2];

        if (Find(u) != Find(v))
        {
            Union(u, v);
            totalWeight += w;
            cnt++;
        }

        if (cnt == V - 1)
            break;
    }

    cout << totalWeight << endl;

    return 0;
}
