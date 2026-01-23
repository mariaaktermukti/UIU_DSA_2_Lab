#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;

    cout << "enter vertex count" << endl;
    cin >> V;

    cout << "enter edge count" << endl;
    cin >> E;


    vector<vector<pair<int, int>>> graph(V);


    for (int i = 0; i < E; i++)
    {

        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }


    int srcNode;
    cout << "Enter Source Node" << endl;

    cin >> srcNode;

    int visited[V], dist[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = -1;   
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que; //greater<pair<int, int> for min heap

    dist[srcNode] = 0;

    que.push({dist[srcNode], srcNode}); 

    while (!que.empty())
    {
        pair<int, int> visit = que.top(); 

        int u = visit.second;
        visited[u] = 1;
        que.pop();

        for (auto adj : graph[u])
        {
            int adjNode = adj.first;
            int weight = adj.second;

            if (visited[adjNode] != 1)
            {

                if (dist[adjNode] > dist[u] + weight)
                {
                    dist[adjNode] = dist[u] + weight;
                    que.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "src to " << i << ": inf" << endl;
        }
        cout << "src to " << i << " " << ": " << dist[i] << endl;
    }
}