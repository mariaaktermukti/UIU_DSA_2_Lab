#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int V = 2524;
    int count = 0;

    sort(coins.begin(), coins.end(), greater<int>()); 

    for(int coin: coins) 
    {
        if(V == 0) break;
        int take = V / coin;
        V -= take * coin;
        count += take;
        if(take > 0)
            cout << coin << " coin: " << take << " times" << endl;
    }

    cout << "Minimum coins needed: " << count << endl;
}
