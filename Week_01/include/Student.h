#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

template <typename T>
class Student {
private:
    std::string name;
    int age;
    T* gpa;  // Dynamically allocated GPA

public:
    // Constructor
    Student(std::string n, int a, T g);

    // Destructor
    ~Student();

    // Copy Constructor (deep copy)
    Student(const Student& other);

    // Copy Assignment Operator (deep copy)
    Student& operator=(const Student& other);

    // Move Constructor (efficient transfer)
    Student(Student&& other) noexcept;

    // Move Assignment Operator (efficient transfer)
    Student& operator=(Student&& other) noexcept;

    // Overloaded > operator for GPA comparison
    bool operator>(const Student<T>& other) const;

    T getGPA() const { return *gpa; }

    // Display function
    void display() const;
};

// Include template implementation
#include "../src/Student.tpp"

#endif // STUDENT_H