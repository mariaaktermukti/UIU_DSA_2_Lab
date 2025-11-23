#include <iostream>
#include <vector>     // include the vector header
#include <algorithm>  // for sort()
using namespace std;

int main() {

    // Declare a vector of integers
    vector<int> vec;

    // Insert elements into the vector using push_back()
    vec.push_back(1);
    vec.push_back(10);

    // Accessing elements using index
    cout << vec[0] << endl;        // Direct index access (no bounds checking)
    cout << vec.at(1) << endl;     // Safe access (throws exception if out of range)

    // Display size of the vector
    cout << "Size of vector: " << vec.size() << endl;

    // Traversing elements using a normal for loop
    cout << "Elements (using index loop): ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Traversing elements using a for-each loop
    cout << "Elements (using range-based for loop): ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    // Update element at index 0
    vec[0] = 5;
    cout << "After updating index 0: " << vec[0] << endl;

    // Remove the last element using pop_back()
    vec.pop_back();
    cout << "Size after pop_back(): " << vec.size() << endl;

    // Insert an element at the beginning (index 0)
    vec.insert(vec.begin(), 14);
    cout << "After inserting 14 at beginning: " << vec[0] << endl;

    cout << "Vector elements: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    // Insert element at index 2 (3rd position)
    vec.insert(vec.begin() + 2, 15);
    cout << "Element at index 2: " << vec[2] << endl;

     cout << "Vector elements: ";
    for (int x : vec) {
        cout << x << " ";
    }

    // Remove element at index 1
    vec.erase(vec.begin() + 1);
    cout << "After erasing index 1: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    // Sort vector in ascending order
    sort(vec.begin(), vec.end());

    cout << "After sorting: ";
    for (int x : vec) {
        cout << x << " ";
    }

    cout << endl;
     // Sort vector in descending order
    sort(vec.begin(), vec.end(),greater<int>());

    cout << "After sorting: ";
    for (int x : vec) {
        cout << x << " ";
    }

    return 0;
}
