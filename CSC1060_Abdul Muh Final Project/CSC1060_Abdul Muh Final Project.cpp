// Student Grade Management System
// Name: Abdul Moqtadir 
// Date: 4/30/2025
// Course: C++ Programming
// 
// This program helps Students and teachers for their grading system.
// It can:
// - Add new students
// - Add grades
// - Show who's passing/failing
// - Save everything to a file
// 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 25;    // max students
const int MAXG = 5;    // max grades per student

// arrays to store everything
string names[MAX];
int id[MAX];
float grade[MAX][MAXG];
int numGrades[MAX];
float avg[MAX];
int total = 0;

float getAvg(float g[], int num) {
    if (num == 0) return 0;
    float sum = 0;
    for (int i = 0; i < num; i++) {
        sum = sum + g[i];
    }
    return sum / num;
}

bool passed(float g) {
    return (g >= 70);  // need 70 to pass
}

void readStuff() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "cant find file :(\n";
        return;
    }

    string line;
    while (getline(file, line) && total < MAX) {
        int comma = line.find(",");
        names[total] = line.substr(0, comma);
        line = line.substr(comma + 1);

        comma = line.find(",");
        id[total] = stoi(line.substr(0, comma));
        line = line.substr(comma + 1);

        numGrades[total] = 0;
        while (comma != -1 && numGrades[total] < MAXG) {
            comma = line.find(",");
            grade[total][numGrades[total]] = stof(line.substr(0, comma));
            numGrades[total]++;
            if (comma != -1) line = line.substr(comma + 1);
        }

        avg[total] = getAvg(grade[total], numGrades[total]);
        total++;
    }
    file.close();
}

void save() {
    ofstream file("students.txt");
    for (int i = 0; i < total; i++) {
        file << names[i] << "," << id[i];
        for (int j = 0; j < numGrades[i]; j++) {
            file << "," << grade[i][j];
        }
        file << endl;
    }
    file.close();
}

void menu() {
    cout << "\n~~~ Grade Manager ~~~\n"
        << "1) See all students\n"
        << "2) Add a student\n"
        << "3) Give a grades\n"
        << "4) Who's passing?\n"
        << "5) Who's failing?\n"
        << "6) Save and quit\n"
        << "choose one: ";
}

void showAll() {
    if (total == 0) {
        cout << "there is no students yet!\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "---------------\n";
        cout << "Name: " << names[i] << endl;
        cout << "ID #: " << id[i] << endl;
        cout << "Grades: ";
        if (numGrades[i] == 0) {
            cout << "none yet";
        }
        else {
            for (int j = 0; j < numGrades[i]; j++) {
                cout << grade[i][j];
                if (j != numGrades[i] - 1) cout << ", ";
            }
        }
        cout << "\nAverage: " << (numGrades[i] == 0 ? "N/A" : to_string(avg[i]) + "%");
        cout << "\nStatus: " << (passed(avg[i]) ? "PASS" : "FAIL") << endl;
    }
}

int main() {
    readStuff();

    bool keepGoing = true;
    while (keepGoing) {
        menu();
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showAll();
        }
        else if (choice == 2) {
            if (total >= MAX) {
                cout << "sorry, class is full!\n";
                continue;
            }
            cout << "what are their name? ";
            getline(cin, names[total]);
            cout << "what is their id? ";
            cin >> id[total];
            numGrades[total] = 0;
            avg[total] = 0;
            total++;
            cout << "ok, added!\n";
        }
        else if (choice == 3) {
            string name;
            cout << "which student? ";
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < total; i++) {
                if (names[i] == name) {
                    found = true;
                    if (numGrades[i] >= MAXG) {
                        cout << "too many grades!\n";
                        break;
                    }
                    float newGrade;
                    cout << "what grade? ";
                    cin >> newGrade;
                    cin.ignore(); // Clear the input buffer

                    if (cin.fail()) {
                        cin.clear(); // Clear error flags
                        cin.ignore(10000, '\n'); // Clear bad input
                        cout << "Please enter a valid number grade!\n";
                        break;
                    }

                    grade[i][numGrades[i]] = newGrade;
                    numGrades[i]++;
                    avg[i] = getAvg(grade[i], numGrades[i]);
                    cout << "ok, added! new average: " << avg[i] << "%\n";
                    break;
                }
            }
            if (!found) cout << "cannot find them!\n";
        }
        else if (choice == 4) {
            cout << "\nPassing Students:\n";
            bool found = false;
            for (int i = 0; i < total; i++) {
                if (passed(avg[i])) {
                    cout << names[i] << " - " << avg[i] << "%\n";
                    found = true;
                }
            }
            if (!found) cout << "none is passing :(\n";
        }
        else if (choice == 5) {
            cout << "\nFailing Students:\n";
            bool found = false;
            for (int i = 0; i < total; i++) {
                if (!passed(avg[i])) {
                    cout << names[i] << " - " << avg[i] << "%\n";
                    found = true;
                }
            }
            if (!found) cout << "everyone is passing!\n";
        }
        else if (choice == 6) {
            save();
            keepGoing = false;
        }
        else {
            cout << "Choose 1-6 plz!\n";
        }
    }

    cout << "\ncya later! Thanks for using our program\n";
    return 0; 
}