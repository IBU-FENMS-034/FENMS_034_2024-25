#include <algorithm>
#include <iostream>
#include "../include/StudentList.h"

int main() {
    std::cout << "\n";
    std::cout << "=== Testing Constructor and Object Creation ===\n";
    Student<double> s1("Alice", 20, 3.8);
    Student<double> s2("Bob", 22, 3.6);
    Student<double> s3("Charlie", 21, 3.9);

    s1.display();
    s2.display();
    s3.display();

    std::cout << "\n=== Testing Copy Constructor ===\n";
    Student<double> s4 = s1;  // Copy Constructor
    s4.display();

    std::cout << "\n=== Testing Copy Assignment Operator ===\n";
    s2 = s1;  // Copy Assignment
    s2.display();

    std::cout << "\n=== Testing Move Constructor ===\n";
    Student<double> s5 = std::move(s3);  // Move Constructor
    s5.display();

    std::cout << "\n=== Testing Move Assignment Operator ===\n";
    Student<double> s6("David", 23, 3.5);
    s6 = std::move(s4);  // Move Assignment
    s6.display();

    Student<double> s10("Alice", 20, 3.8);
    Student<double> s12("Bob", 22, 3.6);

    std::cout << "\n=== Testing Operator Overloading (> for GPA comparison) ===\n";
    if (s10 > s12)
        std::cout << s10.getGPA() << " is greater than " << s12.getGPA() << "\n";
    else
        std::cout << s10.getGPA() << " is not greater than " << s12.getGPA() << "\n";

    std::cout << "\n=== Testing Student List and Iterators ===\n";
    StudentList<double> studentList;
    studentList.addStudent(s1);
    studentList.addStudent(s2);
    studentList.addStudent(s5);
    studentList.addStudent(s6);

    std::cout << "Student List before sorting:\n";
    for (const auto& student : studentList) student.display();

    std::sort(studentList.begin(), studentList.end(), [](const Student<double>& a, const Student<double>& b) {
        return a > b;  // Uses overloaded > operator
    });

    std::cout << "\nStudent List after sorting (by GPA descending):\n";
    for (const auto& student : studentList) student.display();

    std::cout << "\n=== Testing Destructor Cleanup ===\n";
    return 0;
}