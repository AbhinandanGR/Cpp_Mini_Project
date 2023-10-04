#include <iostream>
#include <string>
using namespace std;

// Function to calculate grade points based on the grade
int calculateGradePoints(char grade) {
    switch (grade) {
    	case 'S':
        case 's':
            return 10;
        case 'A':
        case 'a':
            return 9;
        case 'B':
        case 'b':
            return 8;
        case 'C':
        case 'c':
            return 7;
        case 'D':
        case 'd':
            return 5;
        case 'E':
        case 'e':
            return 4;
        case 'F':
        case 'f':
            return 0;
        default:
            return -1; // Invalid grade
    }
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;
    cout << endl;

    string subjectNames;//[numSubjects];
    double subjectCredits[numSubjects];
    char subjectGrades[numSubjects];

    // Input subject names, credit , and grades
    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter the name of subject " << i + 1 << ": ";
        cin >> subjectNames;

        cout << "Enter the credit for " << subjectNames << ": ";
        cin >> subjectCredits[i];

        cout << "Enter the grade for " << subjectNames << " (S/A/B/C/D/E/F): ";
        cin >> subjectGrades[i];
        cout << endl;
    }

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    // Calculate total grade points and credits
    for (int i = 0; i < numSubjects; i++) {
        double gradePoints = calculateGradePoints(subjectGrades[i]);

        if (gradePoints == -1) {
            cout << "Invalid grade entered for " << subjectNames[i] << endl;
            goto end;
        }
        
        if(gradePoints == 0){
      	    cout << "You have failed" << endl;
      	    goto end;
      	}

        totalCredits = totalCredits + subjectCredits[i];
        totalGradePoints = totalGradePoints + (gradePoints * subjectCredits[i]);
    }

    if (totalCredits > 0) {
        double sgpa = totalGradePoints / totalCredits;
        cout << "SGPA: " << sgpa << endl;
    } else {
        cout << "No valid grades entered to calculate SGPA." << endl;
    }
    
    end:
    return 0;
}

