#include "StudentRecord.h"
#include "StudentRecord.cpp"
#include <iostream>

using namespace std;

int main() {
    //student class
    Student student1;
    student1.print();



    Student student2;

    student2.setName("Alice");
    student2.setEmail("slime@gmail.com");
    student2.setYear(2028);
    student2.print();

    

    


return 0;
}
 
