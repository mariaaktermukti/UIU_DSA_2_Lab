#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    cout << "Coordinates:\n";
    for (auto p : points)
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
