#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value, weight, ratio;
};

int main() 
{
    int n;
    cin >> n;

    vector<Item> items(n);

    for(int i = 0; i < n; i++) 
    {
        string name;
        cin >> name >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    int k; 
    cin >> k;

    vector<double> W(k);
    double totalCapacity = 0;

    for(int i = 0; i < k; i++) 
    {
        cin >> W[i];
        totalCapacity += W[i];
    }

    sort(items.begin(), items.end(), [](Item &a, Item &b){
        return a.ratio > b.ratio;
    });

    double totalProfit = 0;

    for(auto &it : items) 
    {
        if(totalCapacity <= 0) break;

        if(it.weight <= totalCapacity) 
        {
            totalProfit += it.value;
            totalCapacity -= it.weight;
        } 
        else 
        {
            totalProfit += it.ratio * totalCapacity;
            totalCapacity = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total Profit: " << totalProfit << " taka\n";

    return 0;
}
