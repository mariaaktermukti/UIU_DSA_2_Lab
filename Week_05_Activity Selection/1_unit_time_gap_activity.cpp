#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Train
{
public:
    int arrival;
    int departure;
    string id;
};

bool sortByDeparture(const Train &t1, const Train &t2)
{
    return t1.departure < t2.departure;
}

int main()
{

    vector<pair<int, int>> input = {
        {8, 12},
        {6, 9},
        {11, 14},
        {2, 7},
        {1, 7},
        {12, 20},
        {7, 12},
        {13, 19}};

    vector<Train> trains;

    for (int i = 0; i < input.size(); i++)
    {
        Train t;
        t.arrival = input[i].first;
        t.departure = input[i].second;
        t.id = "T" + to_string(i + 1);
        trains.push_back(t);
    }

    sort(trains.begin(), trains.end(), sortByDeparture);

    cout << "Selected Trains:\n";

    int count = 0;
    int lastDeparture = -1;

    for (const Train &t : trains)
    {

        if (t.arrival >= lastDeparture + 1)
        {
            cout << t.id << " " << t.arrival << ", " << t.departure << "\n";
            count++;
            lastDeparture = t.departure;
        }
    }

    cout << "\nMaximum trains using the platform: " << count << endl;

    return 0;
}
