#include <bits/stdc++.h>
using namespace std;

int Find(int x, int parent[])
{
    if (parent[x] == -1)
        return x;
    return parent[x] = Find(parent[x], parent);
}

void Union(int u, int v, int parent[], int Rank[])
{
    int rootU = Find(u, parent);
    int rootV = Find(v, parent);

    if (rootU == rootV)
        return;

    if (Rank[rootU] > Rank[rootV])
    {
        parent[rootV] = rootU;
        Rank[rootU] += Rank[rootV];
    }
    else
    {
        parent[rootU] = rootV;
        Rank[rootV] += Rank[rootU];
    }
}

int main()
{
    int N;
    cin >> N;
    pair<int, int> stations[N];
    for (int i = 0; i < N; i++)
    {
        cin >> stations[i].first >> stations[i].second;
    }

    vector<vector<int>> edgeList;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int w = abs(stations[i].first - stations[j].first) + abs(stations[i].second - stations[j].second);
            edgeList.push_back({w, i, j});
        }
    }

    int parent[N], Rank[N];
    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        Rank[i] = 1;
    }

    sort(edgeList.begin(), edgeList.end());

    int totalCost = 0;
    vector<vector<int>> mstEdges;

    for (auto e : edgeList)
    {
        int w = e[0];
        int u = e[1];
        int v = e[2];

        if (Find(u, parent) != Find(v, parent))
        {
            Union(u, v, parent, Rank);
            totalCost += w;
            mstEdges.push_back({u, v, w});
        }
        if ((int)mstEdges.size() == N - 1)
        {
            break;
        }
            
    }

    cout << totalCost << endl;

    return 0;
}
