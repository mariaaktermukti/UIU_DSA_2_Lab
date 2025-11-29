#include <iostream>
using namespace std;

void printReverse(int arr[], int idx, int n){
    if(idx == n) return;
    printReverse(arr, idx + 1, n);
    cout << arr[idx] << " ";
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    printReverse(arr, 0, n);
    return 0;
}
