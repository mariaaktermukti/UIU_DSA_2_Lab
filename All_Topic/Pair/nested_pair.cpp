#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, pair<int, string>> student;

    student.first = 1;               
    student.second.first = 22;       
    student.second.second = "Maria"; 

    cout << "Student ID: " << student.first << endl;
    cout << "Student Age: " << student.second.first << endl;
    cout << "Student Name: " << student.second.second << endl;


    pair<int, pair<int, string>> student2 = {2, {26, "shifat"}};

    cout << "\nStudent 2 Info:" << endl;
    cout << "ID: " << student2.first << ", Age: "
         << student2.second.first << ", Name: "
         << student2.second.second << endl;

    return 0;
}
