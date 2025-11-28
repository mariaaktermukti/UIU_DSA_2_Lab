#include <iostream>
using namespace std;

struct Student {
    string name;
    int id;
    double cgpa;
};

Student findTopStudent(Student arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;

    Student leftTop = findTopStudent(arr, left, mid);
    Student rightTop = findTopStudent(arr, mid + 1, right);

    if (leftTop.cgpa >= rightTop.cgpa) {
        return leftTop;
    } else {
        return rightTop;
    }
}

int main() {
    Student students[] = {
        {"Alice", 101, 3.75},
        {"Bob", 102, 3.9},
        {"Charlie", 103, 3.65},
        {"David", 104, 3.95},
        {"Eva", 105, 3.85}
    };

    int n = sizeof(students) / sizeof(students[0]);

    Student topStudent = findTopStudent(students, 0, n - 1);

    cout << "Top student is:\n";
    cout << "Name: " << topStudent.name << "\n";
    cout << "ID: " << topStudent.id << "\n";
    cout << "CGPA: " << topStudent.cgpa << endl;

    return 0;
}
