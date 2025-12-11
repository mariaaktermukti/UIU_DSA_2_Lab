#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Activity
{
public:
    string id;
    int startTime;
    int finishTime;
};

bool compareByFinish(const Activity &a1, const Activity &a2)
{
    return a1.finishTime < a2.finishTime;
}

int main()
{

    vector<int> startTimes = {1, 3, 0, 5, 8, 5};
    vector<int> finishTimes = {2, 4, 6, 7, 9, 9};

    vector<Activity> activities;

    for (int i = 0; i < startTimes.size(); i++)
    {
        Activity a;
        a.id = "A" + to_string(i);
        a.startTime = startTimes[i];
        a.finishTime = finishTimes[i];
        activities.push_back(a);
    }

    sort(activities.begin(), activities.end(), compareByFinish);

    int lastFinishTime = 0;
    int count = 0;

    cout << "Selected Activities:\n";

    for (const Activity &act : activities)
    {
        if (act.startTime >= lastFinishTime)
        {
            count++;
            cout << act.id
                 << " (Start: " << act.startTime
                 << ", Finish: " << act.finishTime << ")\n";
            lastFinishTime = act.finishTime;
        }
    }

    cout << "\nTotal Activities Selected: " << count << endl;

    return 0;
}
