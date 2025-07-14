#ifndef CLUBROSTER_H
#define CLUBROSTER_H

#include <string>

#include "StudentRecord.h"

struct Node {
    Student student; // The student data
    Node* next;  // Pointer to the next node

    Node(Student s){ //A new node with student data
        student = s;
        next = nullptr;
    }

};

 // Class to manage a club roster
class ClubRoster{
    private: 
        Node* head;
        int count; 

    public: 
        ClubRoster(); // Constructor

        ~ClubRoster();  // Destructor

        bool addStudent(Student student); // Add a student to the roster

        bool removeStudent(std::string name); // Remove a student from the roster

        void printRoster(); // Print all students in the roster

        int getSize(); // Get the number of students in the roster

        bool isEmpty(); // Check if the roster is empty

        Node* getHead() const; 
};

#endif 
