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

    pair<double, double> stations[N];
    for (int i = 0; i < N; i++)
    {
        cin >> stations[i].first >> stations[i].second;
    }

    vector<vector<double>> edgeList;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double x1 = stations[i].first;
            double y1 = stations[i].second;
            double x2 = stations[j].first;
            double y2 = stations[j].second;

            double w = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
            edgeList.push_back({w, (double)i, (double)j});
        }
    }

    int parent[N], Rank[N];
    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        Rank[i] = 1;
    }

    sort(edgeList.begin(), edgeList.end());

    double totalCost = 0.0;
    int edgesUsed = 0;

    for (auto e : edgeList)
    {
        double w = e[0];
        int u = (int)e[1];
        int v = (int)e[2];

        if (Find(u, parent) != Find(v, parent))
        {
            Union(u, v, parent, Rank);
            totalCost += w;
            edgesUsed++;
        }

        if (edgesUsed == N - 1)
            break;
    }

    cout << fixed << setprecision(2) << totalCost << endl;
    return 0;
}
