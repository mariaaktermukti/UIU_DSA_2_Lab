#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> student(n);

    for(int i = 0; i < n; i++) {
        cin >> student[i].first >> student[i].second;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(student[i].second > student[j].second) {
                swap(student[i], student[j]);
            }
        }
    }

    cout << "\nAfter sorting (by marks):\n";
    for(int i = 0; i < n; i++) {
        cout << student[i].first << " " << student[i].second << endl;
    }

    return 0;
}
