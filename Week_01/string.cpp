#include <iostream>
//#include <string> // must include this header file
using namespace std;

int main() {
    // String initialization
    string str1 = "Hello_World";
    string str2 = "Hola World";

    // Find position of a substring
    int position = str1.find("World");
    cout << "The word 'World' starts at position: " << position << endl;

    // Extract substring (start index, length)
    string subString = str1.substr(1, 5);
    cout << "Substring: " << subString << endl;

    // Another string example
    string str = "data structure";
    string str3 = "Algorithms ";

    // Length of a string
    int length = str.length();
    cout << "Length: " << length << endl;

    // Character at a particular index
    char ch = str.at(2);
    char ch2 = str[3];
    cout << "Character at index 2: " << ch << endl;
    cout << "Character at index 3: " << ch2 << endl;

    // Concatenate strings
    string course_name = str + " and " + str3 + to_string(2); //converts numeric values(int, float, double, long, etc.) into a string.
    cout << "Course name: " << course_name << endl;

    // Comparing strings
    if (str == str3)
        cout << "Equal strings" << endl;
    else
        cout << "Not equal" << endl;

    // Convert a character to uppercase
    str[3] = toupper(str[3]);
    cout << "After toupper at index 3: " << str << endl;

    // Demonstrate insert, replace, erase
    string demo = "hello!!!";

    // Insert a string at an index
    demo.insert(5, " world");  // "hello world!!!"
    cout << demo << endl;

    // Replace part of a string : replace(start, len, "text")
    demo.replace(6, 6, "Mina");  // "hello Mina!!!"
    cout << demo << endl;

    // Erase part of a string: erase(start, len)
    demo.erase(6, 4); // remove "Mina"
    cout << demo << endl;

    return 0;
}

