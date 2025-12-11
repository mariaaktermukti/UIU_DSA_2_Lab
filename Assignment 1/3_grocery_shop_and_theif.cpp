#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    double weight;   
    double profit;   
    double density; 
};

int main() {
    vector<Item> items = {
        {"Rice", 12, 840, 0},
        {"Salt", 10, 870, 0},
        {"Saffron", 8, 2000, 0},
        {"Sugar", 5, 500, 0}
    };

    for(auto &it: items) 
    {
        it.density = it.profit / it.weight;
    }

    sort(items.begin(), items.end(), [](Item a, Item b){ return a.density > b.density; });

    double knapsack = 9; 
    int thief_count = 0;

    vector<vector<pair<string, double>>> thieves_items; 
    vector<double> thieves_profit; 

    while(true) {
        bool shop_empty = true;
        for(auto it: items) 
        {
            if(it.weight > 0) 
            { 
                shop_empty = false;
                 break; 
            }
        }
        if(shop_empty) break; 

        thief_count++;
        double capacity = knapsack;
        double profit = 0;
        vector<pair<string, double>> carried;

        for(auto &it: items) 
        {
            if(it.weight <= 0) continue;

            double take = min(it.weight, capacity); 
            it.weight -= take;
            capacity -= take;
            profit += take * it.density;
            carried.push_back({it.name, take});

            if(capacity <= 0) break;
        }

        thieves_items.push_back(carried);
        thieves_profit.push_back(profit);
    }

    cout << "Number of thieves needed: " << thief_count << endl;
    for(int i=0; i<thief_count; i++) 
    {
        cout << "Thief " << i+1 << " carries: ";
        for(auto x: thieves_items[i]) 
        {
            cout << x.second << " kg " << x.first << ", ";
        }
        cout << "Profit: " << thieves_profit[i] << endl;
    }
}
