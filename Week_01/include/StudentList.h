#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <vector>

template <typename T>
class StudentList {
private:
    std::vector<Student<T>> students;

public:
    void addStudent(const Student<T>& s);


    using iterator = typename std::vector<Student<T>>::iterator;
    using const_iterator = typename std::vector<Student<T>>::const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};


#include "../src/StudentList.tpp"

#endif // STUDENTLIST_H