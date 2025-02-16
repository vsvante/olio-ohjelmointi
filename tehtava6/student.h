#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    Student(string name, int age);

    string getNimi() const;
    int getAge() const;
    void printStudentInfo() const;

    static void printAllStudents(const vector<Student>& studentList);
    static void sortByName(vector<Student>& studentList);
    static void sortByAge(vector<Student>& studentList);
    static bool findStudentByName(const vector<Student>& studentList, const string& name);

private:
    string name;
    int age;
};

#endif // STUDENT_H
