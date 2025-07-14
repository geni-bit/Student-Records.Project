#include <iostream>
#include <fstream>
#include <sstream>

#include "club_roster.hpp"

using namespace std;

// Constructor 
ClubRoster::ClubRoster() {
    head = nullptr;
    count = 0;
}

// Destructor
ClubRoster::~ClubRoster() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Get the number of students in the roster
int ClubRoster::getSize() {
    return count;
}

// Check if the roster is empty
bool ClubRoster::isEmpty() {
    return head == nullptr;
}

// Add a student to the roster
bool ClubRoster::addStudent(Student student) {
    //Checking if a student with the same name already exists
    Node* current = head;
    while (current != nullptr) {
        if (current->student.getName() == student.getName()) {
            cout << "A student with that name already exists." << endl;
            return false;
        }
        current = current->next;
    }
    
    // Create a new node for the student
    Node* newNode = new Node(student);
    
    // If the list is empty, make this the first node
    if (head == nullptr) {
        head = newNode;
    } else {
        //Add to the end of the list
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    count += 1;
    return true;
}

// Remove a student from the roster
bool ClubRoster::removeStudent(std::string name) {
    // If roster is empty
    if (head == nullptr) {
        cout << "The club Roster is empty." << endl;
        return false;
    }
    
    //if the first student name matches
    if (head->student.getName() == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count -= 1;
        return true;
    }
    
    // Search through the list
    Node* current = head;
    while (current->next != nullptr) {
        // If we found the student, we remove them
        if (current->next->student.getName() == name) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count -= 1;
            return true;
        }
        current = current->next;
    }

    //If the student isn't in the roster
    cout << "The Student is not found in the roster" << endl;
    return false;
}

void ClubRoster::printRoster(){
    if (head == nullptr) {
        cout << "The roster is empty." << endl;
        return;
    }
    
    cout << "Club Roster (" << count << " students):" << endl;

    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        cout << index << ". Name: " << current->student.getName() 
             << ", Email: " << current->student.getEmail()
             << ", Year: " << current->student.getYear() << endl;
        current = current->next;
        index += 1;
    }
}

Node* ClubRoster::getHead() const{
    return head;
}
