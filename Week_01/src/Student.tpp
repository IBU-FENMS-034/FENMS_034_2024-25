#include "../include/Student.h"


template <typename T>
Student<T>::Student(std::string n, int a, T g) : name(n), age(a) {
    gpa = new T(g);
    std::cout << "Constructor: " << name << " created with GPA " << *gpa << "\n";
}


template <typename T>
Student<T>::~Student() {
    delete gpa;
    std::cout << "Destructor: " << name << " destroyed\n";
}


template <typename T>
Student<T>::Student(const Student& other) : name(other.name), age(other.age) {
    gpa = new T(*other.gpa);
    std::cout << "Copy Constructor: " << name << " copied\n";
}


template <typename T>
Student<T>& Student<T>::operator=(const Student& other) {
    if (this == &other) return *this; // Self-assignment check

    delete gpa;
    name = other.name;
    age = other.age;
    gpa = new T(*other.gpa);
    std::cout << "Copy Assignment: " << name << " assigned\n";
    return *this;
}

template <typename T>
Student<T>::Student(Student&& other) noexcept : name(std::move(other.name)), age(other.age), gpa(other.gpa) {
    other.gpa = nullptr;
    std::cout << "Move Constructor: " << name << " moved\n";
}

template <typename T>
Student<T>& Student<T>::operator=(Student&& other) noexcept {
    if (this == &other) return *this;

    delete gpa;
    name = std::move(other.name);
    age = other.age;
    gpa = other.gpa;
    other.gpa = nullptr;
    std::cout << "Move Assignment: " << name << " move assigned\n";
    return *this;
}

template <typename T>
bool Student<T>::operator>(const Student<T>& other) const {
    return *gpa > *other.gpa;
}

template <typename T>
void Student<T>::display() const {
    std::cout << "Student: " << name << ", Age: " << age << ", GPA: " << *gpa << "\n";
}