#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int rankArr[1000];

int Find(int x)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = Find(parent[x]);
}

bool UnionSet(int u, int v)
{
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv)
        return false;
    if (rankArr[pu] < rankArr[pv])
        swap(pu, pv);
    parent[pv] = pu;
    rankArr[pu] += rankArr[pv];
    return true;
}

int main()
{
    int V, E;
    cout << "Enter vertex and edge number" << endl;
    cin >> V >> E;

    vector<vector<int>> edgeList;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({w, u, v, i});
    }

    int k;
    cin >> k;
    vector<int> preselected(k);
    for (int i = 0; i < k; i++)
        cin >> preselected[i];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        rankArr[i] = 1;
    }

    vector<vector<int>> mstEdges;
    int totalWeight = 0;

    for (int i = 0; i < k; i++)
    {
        int idx = preselected[i];
        int u = edgeList[idx][1];
        int v = edgeList[idx][2];
        int w = edgeList[idx][0];
        if (UnionSet(u, v))
        {
            totalWeight += w;
            mstEdges.push_back({w, u, v});
        }
    }

    sort(edgeList.begin(), edgeList.end());

    for (auto e : edgeList)
    {
        int w = e[0];
        int u = e[1];
        int v = e[2];
        int idx = e[3];

        bool already = false;
        for (auto &m : mstEdges)
        {
            if (m[0] == w && ((m[1] == u && m[2] == v) || (m[1] == v && m[2] == u)))
            {
                already = true;
                break;
            }
        }
        if (already)
            continue;

        if (UnionSet(u, v))
        {
            totalWeight += w;
            mstEdges.push_back({w, u, v});
        }
        if ((int)mstEdges.size() == V - 1)
        {
            break;
        }
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
    cout << "Edges in MST:" << endl;
    for (auto e : mstEdges)
    {
        cout << e[1] << " - " << e[2] << " (" << e[0] << ")" << endl;
    }

    return 0;
}
