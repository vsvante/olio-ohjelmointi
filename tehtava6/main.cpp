#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

int main() {
    int selection = 0;
    vector<Student> studentList;

    Student a("Perttu", 20);
    Student b("Tuomas", 19);
    Student c("Liisa", 23);
    Student d("Eetu", 22);

    studentList.push_back(a);
    studentList.push_back(b);
    studentList.push_back(c);
    studentList.push_back(d);

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection) {

        case 1:
            Student::printAllStudents(studentList);
            break;

        case 2:
            Student::sortByName(studentList);
            break;

        case 3:
            Student::sortByAge(studentList);
            break;

        case 4: {
            cout << "Student to be found name = ? ";
            string etsittavanimi;
            cin >> etsittavanimi;

            Student::findStudentByName(studentList, etsittavanimi);
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}
