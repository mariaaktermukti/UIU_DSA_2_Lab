#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    double weight;
    double profit;
    double density;
};

int main()
{
    vector<Item> items = {
        {12, 840, 840.0 / 12},
        {10, 870, 870.0 / 10},
        {8, 2000, 2000.0 / 8},
        {5, 500, 500.0 / 5}};

    double knapsack = 9;
    double total_profit = 0;

    sort(items.begin(), items.end(), [](Item a, Item b)
         { return a.density > b.density; });

    while (true)
    {
        bool shop_empty = true;
        for (auto it : items)
        {
            if (it.weight > 0)
            {
                shop_empty = false;
                break;
            }
        }
        if (shop_empty)
            break;

        double capacity = knapsack;

        for (auto &it : items)
        {
            if (it.weight <= 0)
                continue;
            double take = min(it.weight, capacity);
            it.weight -= take;
            capacity -= take;
            total_profit += take * it.density;
            if (capacity <= 0)
            {
                break;
            }
        }
    }

    cout << total_profit << endl;
}
