#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int>coins= {1,2,5,10,20,50,100,500,1000};
    int target;
    cout<< "Enter the target : " << endl;
    cin>> target;
    int no_coins=0;

    sort(coins.begin(), coins.end(), greater<int>());

    for(int i=0; i< coins.size();i++)
    {
        int coin= coins[i];
        if(target> 0)
        {
            int need= target/coin;

            if(need>0)
            {
                cout << coin << " used " << need << " times. " << endl;
            }

            no_coins= no_coins+ need;
            target = target - coin* need;
        }
        else{
            break;
        }
        
    }

    cout <<"Total coins used : " << no_coins << endl;
    
    return 0;
}