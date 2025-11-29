#include <iostream>
using namespace std;

int countEven(int arr[], int l, int r){
    if(l > r) return 0;
    int add = 0;
    if(arr[l] % 2 == 0) add = 1;
    return add + countEven(arr, l + 1, r);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << countEven(arr, 0, n - 1);
    return 0;
}
