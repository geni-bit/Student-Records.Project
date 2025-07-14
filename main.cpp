#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "club_roster.hpp"
#include "StudentRecord.h"

using namespace std;

void loadRosterFromFile(const string& filename, ClubRoster& roster) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file for reading." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string name, email;
        int year;

        // Parse the line assuming it's in the format: name,email,year
        if (getline(ss, name, ',') && getline(ss, email, ',') && ss >> year) {
            Student student(name, email, year);
            roster.addStudent(student);
        } else {
            cerr << "Error." << endl;
        }
    }

    inputFile.close();
}

void saveRosterToFile(const string& filename, const ClubRoster& roster) {
    ofstream outputFile(filename, ofstream::trunc);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return;
    }

    Node* current = roster.getHead(); 
    while (current != nullptr) {
        outputFile << current->student.getName() << ","
                   << current->student.getEmail() << ","
                   << current->student.getYear() << endl;
        current = current->next;
    }

    outputFile.close();
}


void printMenu() {

    cout << "1. Print club roster" << endl;
    cout << "2. Add a student" << endl;
    cout << "3. Remove a student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: " << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input file>" << endl;
        return 1;
    }

    string filename = argv[1];
    ClubRoster roster;

    // Load the roster from file
    loadRosterFromFile(filename, roster);

    int choice;
    string name, email;
    int year;

    while (true) {
        printMenu();
        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin

        switch (choice) {
            case 1: {
                roster.printRoster();
                break;
            }
            case 2: {
                cout << "Enter student's name: ";
                getline(cin, name);
                cout << "Enter student's email: ";
                getline(cin, email);
                cout << "Enter student's year: ";
                cin >> year;
                cin.ignore(); // To consume the newline character left by cin

                Student newStudent(name, email, year);
                roster.addStudent(newStudent);
                break;
            }
            case 3: {
                cout << "Enter student's name to remove: ";
                getline(cin, name);

                if (roster.removeStudent(name)) {
                    cout << "Student removed successfully.\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                // Save the roster to the same file
                saveRosterToFile(filename, roster);
                cout << "Roster saved. Exiting program.\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
