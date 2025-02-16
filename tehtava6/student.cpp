#include "student.h"
#include <algorithm>

Student::Student(string name, int age) : name(name), age(age) {}

string Student::getNimi() const {
    return name;
}

int Student::getAge() const {
    return age;
}

void Student::printStudentInfo() const {
    cout << "Student " << name << " Age " << age << endl;
}

void Student::printAllStudents(const vector<Student>& studentList) {
    for (const Student &s: studentList) {
        s.printStudentInfo();
    }
}

void Student::sortByName(vector<Student>& studentList) {
    sort(studentList.begin(), studentList.end(),
         [](const Student &eka, const Student &toka) {
             return eka.getNimi() < toka.getNimi();
         });

    cout << endl << "Sorted by Name:" << endl;
    printAllStudents(studentList);
}

void Student::sortByAge(vector<Student>& studentList) {
    sort(studentList.begin(), studentList.end(),
         [](const Student &eka, const Student &toka) {
             return eka.getAge() < toka.getAge();
         });

    cout << endl << "Sorted by Age:" << endl;
    printAllStudents(studentList);
}

bool Student::findStudentByName(const vector<Student>& studentList, const string& name) {
    auto it = find_if(studentList.begin(), studentList.end(),
                      [&name](const Student &s) {
                          return s.getNimi() == name;
                      });

    if (it != studentList.end()) {
        cout << "Student found: ";
        it->printStudentInfo();
        return true;
    } else {
        cout << "Student not found" << endl;
        return false;
    }
}
