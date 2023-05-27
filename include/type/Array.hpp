#pragma once

#ifndef _TYPE_ARRAY

#define _TYPE_ARRAY

#include <string>
#include <iostream>

template<class T>
class ArrayContainer {
private:
    T* array;
    int size;

public:
    template<class U>
    friend class ArrayContainer;

    ArrayContainer(int size) : size(size) {
        array = new T[size];
    }

    template<class U>
    ArrayContainer(const ArrayContainer<U>& other) : size(other.size) {
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(other.array[i]);
        }
    }

    ~ArrayContainer() {
        std::cout << "remove container!!!" << this << std::endl;
        delete[] array;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }
};

#endif
