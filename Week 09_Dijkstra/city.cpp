#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int, int>> graph[])
{
    vector<int> dist(V + 1, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int V, E, PA, PB;
    cin >> V >> E >> PA >> PB;

    vector<pair<int, int>> graph[V + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    vector<int> dist1 = dijkstra(1, V, graph);
    if (dist1[PA] == INT_MAX)
    {
        cout << -1;
        return 0;
    }

    vector<int> dist2 = dijkstra(PA, V, graph);
    if (dist2[PB] == INT_MAX)
    {
        cout << -1;
        return 0;
    }

    cout << dist1[PA] + dist2[PB] << endl;

    return 0;
}
