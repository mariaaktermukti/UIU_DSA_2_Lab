#include <iostream>
using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

template <typename X, typename Y>
Y sum(X a, Y b) {
    return a + b;
}

int main() {
    cout << myMax<int>(3, 7) << endl;      // 7
    cout << myMax('g', 'e') << endl;  // 'g'
    cout << "sum of int: "    << sum(2, 3)   << endl;   // int
    cout << "sum of double: " << sum(3, 6.9) << endl;   // double
    return 0;
}
