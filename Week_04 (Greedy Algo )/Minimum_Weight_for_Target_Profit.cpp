#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double weight, profit, density;
};

int main() {
    vector<Item> items = {{5,10,0},{4,40,0},{6,30,0}};
    double target_profit = 50;
    double total_weight = 0;
    double current_profit = 0;

    for(auto &it: items) 
    {
        it.density = it.profit / it.weight;
    }

    sort(items.begin(), items.end(), [](Item a, Item b){ return a.density > b.density; });

    for(auto it: items)
    {
        if(current_profit >= target_profit)
        {
            break;
        }
        double remaining_profit = target_profit - current_profit;
        double take_weight = min(it.weight, remaining_profit / it.density);
        total_weight += take_weight;
        current_profit += take_weight * it.density;
    }

    cout << "Minimum weight to achieve profit " << target_profit << " = " << total_weight << endl;
}
