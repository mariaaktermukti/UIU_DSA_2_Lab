#include <bits/stdc++.h>
using namespace std;

class Train {
public:
    int arrival;
    int departure;
    string id; 
};

bool sortByDeparture(const Train &t1, const Train &t2) {
    return t1.departure < t2.departure;
}

int main() {
    vector<pair<int,int>> input = {
        {1000, 1030},
        {840, 1030},
        {850, 1040},
        {1700, 2000},
        {800, 835},
        {1300, 1800},
        {1500, 1650},
        {1200, 1380}
    };

    vector<Train> trains;

    for (int i = 0; i < input.size(); i++) {
        Train t;
        t.arrival = input[i].first;
        t.departure = input[i].second;
        t.id = "T" + to_string(i+1);
        trains.push_back(t);
    }

    sort(trains.begin(), trains.end(), sortByDeparture);

    vector<Train> selected;
    int lastDeparture = -1; 

    for (const Train &t : trains) {
        if (t.arrival >= lastDeparture + 10) {
            selected.push_back(t);
            lastDeparture = t.departure;
        }
    }

    cout << "Selected trains on platform:\n";
    for (const Train &t : selected) {
        cout << t.id << "  [" << t.arrival << ", " << t.departure << "]\n";
    }

    cout << "\nMaximum number of trains: " << selected.size() << endl;

    return 0;
}
