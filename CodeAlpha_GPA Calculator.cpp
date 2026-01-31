#include <iostream>
using namespace std;

int main() {
    int numCourses;
    float totalPoints = 0, totalCredits = 0;

    cout << "--- CGPA Calculator ---" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    for (int i = 1; i <= numCourses; i++) {
        float grade, credits;
        cout << "\nEnter Grade (0.0 - 4.0) for course " << i << ": ";
        cin >> grade;
        cout << "Enter Credit Hours for course " << i << ": ";
        cin >> credits;

        totalPoints += (grade * credits);
        totalCredits += credits;
    }

    if (totalCredits > 0) {
        float cgpa = totalPoints / totalCredits;
        cout << "\nTotal Credits: " << totalCredits;
        cout << "\nYour Final CGPA is: " << cgpa << endl;
    }
    else {
        cout << "\nInvalid credits entered." << endl;
    }

    return 0;
}
