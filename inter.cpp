#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Course {
public:
    string name;
    float grade;
    float credit;

    void input(int index) {
        cout << "\nEnter details for " << name << endl;

        do {
            cout << "Grade Point (0 - 10): ";
            cin >> grade;
        } while (grade < 0 || grade > 10);

        cout << "Credit Hours: ";
        cin >> credit;
    }

    string result() {
        return (grade >= 4) ? "PASS" : "FAIL";
    }
};

char getGrade(float cgpa) {
    if (cgpa >= 9) return 'A';
    else if (cgpa >= 8) return 'B';
    else if (cgpa >= 7) return 'C';
    else if (cgpa >= 6) return 'D';
    else return 'F';
}

int main() {
    int n;
    float totalCredits = 0, totalGradePoints = 0;

    string availableCourses[] = {
        "C++", "DBMS", "Operating Systems",
        "Computer Networks", "Mathematics", "Data Structures"
    };

    int totalAvailable = 6;

    cout << "------ Available Courses ------\n";
    for (int i = 0; i < totalAvailable; i++) {
        cout << i + 1 << ". " << availableCourses[i] << endl;
    }

    cout << "\nEnter number of courses you have taken: ";
    cin >> n;

    Course c[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\nSelect course number for course " << i + 1 << ": ";
        cin >> choice;

        c[i].name = availableCourses[choice - 1];
        c[i].input(i);

        totalGradePoints += c[i].grade * c[i].credit;
        totalCredits += c[i].credit;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n---------------- COURSE DETAILS ----------------\n";
    cout << left << setw(25) << "Course"
         << setw(10) << "Grade"
         << setw(10) << "Credits"
         << setw(10) << "Result" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(25) << c[i].name
             << setw(10) << c[i].grade
             << setw(10) << c[i].credit
             << setw(10) << c[i].result() << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Final CGPA: " << cgpa << endl;
    cout << "Overall Grade: " << getGrade(cgpa) << endl;

    return 0;
}