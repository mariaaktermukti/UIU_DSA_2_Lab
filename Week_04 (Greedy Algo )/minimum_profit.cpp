#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double weight, profit, density;
};

int main() {
    vector<Item> items = {{10,60,0},{20,100,0},{30,120,0}};
    double W = 50;
    double total_profit = 0;

    for(auto &it: items)
    {
        it.density = it.profit / it.weight;
    }

    sort(items.begin(), items.end(), [](Item a, Item b){ return a.density < b.density; });

    for(auto it: items)
    {
        if(W == 0) break;
        double take_weight = min(it.weight, W);
        total_profit += take_weight * it.density;
        W -= take_weight;
    }

    cout << "Minimum profit for given weight = " << total_profit << endl;
}
