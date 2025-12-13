#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n;
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), compare);

    vector<Activity> selected;

    selected.push_back(activities[0]);
    int lastFinish = activities[0].finish;
    int totalTime = activities[0].finish - activities[0].start;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= lastFinish)
        {
            selected.push_back(activities[i]);
            totalTime += (activities[i].finish - activities[i].start);
            lastFinish = activities[i].finish;
        }
    }

    cout << "Maximum number of works = " << selected.size() << endl;
    cout << "Total time required = " << totalTime << " hours" << endl;

    cout << "\nSelected work time slots:\n";
    for (int i = 0; i < selected.size(); i++)
    {
        cout << "Start: " << selected[i].start
             << "  Finish: " << selected[i].finish
             << "  Duration: "
             << (selected[i].finish - selected[i].start)
             << " hour(s)\n";
    }

    return 0;
}
