#include<bits/stdc++.h>
using namespace std;

struct student{
    int id;
    double cgpa;

    student(int i,double c)
    {
        id=i;
        cgpa=c;
    }

    void display()
    {
        cout << "ID: " << id << "CGPA: " << cgpa << endl;
    }
};

bool compareStudent(student s1, student s2)
{
    return s1.cgpa > s2.cgpa;
}


int main()
{
    vector<student> s= {
        student(1,3.6),
        student(1,3.3),
        student(1,3.95),
        student(1,3.75),
        student(1,3.42)
    };

    sort(s.begin(), s.end(), compareStudent);
    cout << "Students sorted in ascending order of CGPA:\n";

    for (student x : s)
    {
         x.display();
    }
       
    return 0;
}