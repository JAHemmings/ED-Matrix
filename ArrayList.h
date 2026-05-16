#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {

private:
    E* elements;
    int max;
    int size;
    int pos;

public:
    ArrayList(int max = DEFAULT_MAX) {
        this->max = max;
        elements = new E[max];
        size = 0;
        pos = 0;
    }

    ~ArrayList() {
        delete[] elements;
    }

    void insert(E element) override {
        if (size == max)
            throw runtime_error("List is full");
        for (int i = size; i > pos; i--) {
            elements[i] = elements[i - 1];
        }
        elements[pos] = element;
        size++;
    }

    void append(E element) override {
        if (size == max)
            throw runtime_error("List is full");
        elements[size] = element;
        size++;
    }

    void setElement(E element) override {
        if (pos == size)
            throw runtime_error("No current element");
        elements[pos] = element;
    }

    E getElement() override {
        if (pos == size)
            throw runtime_error("No current element");
        return elements[pos];
    }

    E remove() override {
        if (size == 0)
            throw runtime_error("List is empty");
        if (pos == size)
            throw runtime_error("No current element");
        E element = elements[pos];
        for (int i = pos; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
        return element;
    }

    void clear() override {
        size = 0;
        pos = 0;
    }

    void goToStart() override {
        pos = 0;
    }

    void goToEnd() override {
        pos = size;
    }

    void goToPos(int pos) override {
        if (pos < 0 || pos > size)
            throw runtime_error("Index out of bounds");
        this->pos = pos;
    }

    void next() override {
        if (pos < size)
            pos++;
    }

    void previous() override {
        if (pos > 0)
            pos--;
    }

    bool atStart() override {
        return pos == 0;
    }

    bool atEnd() override {
        return pos == size;
    }

    int getPos() override {
        return pos;
    }

    int getSize() override {
        return size;
    }

    void print() override {
        cout << "(";
        for (int i = 0; i < size; i++) {
            cout << elements[i];
            if (i == pos)
                cout << "*";
            if (i < size - 1)
                cout << ", ";
        }
        cout << ")" << endl;
    }
};
