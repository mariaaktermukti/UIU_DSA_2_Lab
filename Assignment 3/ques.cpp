#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> from(m), to(m), w(m);

        for (int i = 0; i < m; i++)
        {
            cin >> from[i] >> to[i] >> w[i];
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);

        dist[0] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dist[from[j]] != INF &&
                    dist[from[j]] + w[j] < dist[to[j]])
                {
                    dist[to[j]] = dist[from[j]] + w[j];
                }
            }
        }

        bool negativeCycle = false;
        for (int j = 0; j < m; j++)
        {
            if (dist[from[j]] != INF &&
                dist[from[j]] + w[j] < dist[to[j]])
            {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle)
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }

    return 0;
}
