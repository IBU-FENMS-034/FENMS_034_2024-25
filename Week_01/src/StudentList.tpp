#include "../include/StudentList.h"

template <typename T>
void StudentList<T>::addStudent(const Student<T>& s) {
    students.push_back(s);
}


template <typename T>
typename StudentList<T>::iterator StudentList<T>::begin() { return students.begin(); }

template <typename T>
typename StudentList<T>::iterator StudentList<T>::end() { return students.end(); }

template <typename T>
typename StudentList<T>::const_iterator StudentList<T>::begin() const { return students.begin(); }

template <typename T>
typename StudentList<T>::const_iterator StudentList<T>::end() const { return students.end(); }