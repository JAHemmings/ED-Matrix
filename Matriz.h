#pragma once

#include <iostream>
#include <stdexcept>

#include "ArrayList.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Matriz {
private:

    ArrayList<ArrayList<E>*>* matrix;

    int rows;
    int columns;

    void validate(int row, int col) {

        if (row < 0 || row >= rows ||
            col < 0 || col >= columns)

            throw runtime_error("Indice no existe");
    }

public:

    Matrix(int rows, int columns) {
        if (rows <= 0 || columns <= 0)
            throw runtime_error("Dimansiones invalidas");
        this->rows = rows;
        this->columns = columns;
        matrix = new ArrayList<ArrayList<E>*>();
        for (int i = 0; i < rows; i++) {
            ArrayList<E>* row = new ArrayList<E>();
            for (int j = 0; j < columns; j++) {
                row->append(E());
            }
            matrix->append(row);
        }
    }

    ~Matrix() {
        matrix->go_to_start();
        for (int i = 0; i < rows; i++) {
            ArrayList<E>* row = matrix->get_Element();
            delete row;
            matrix->next();
        }
        delete matrix;
    }

    E getValue(int row, int col) {
        validate(row, col);
        matrix->go_to_pos(row);
        ArrayList<E>* currentRow = matrix->get_Element();
        currentRow->go_to_pos(col);
        return currentRow->get_Element();
    }

    void setValue(int row, int col, E value) {
        validate(row, col);
        matrix->go_to_pos(row);
        ArrayList<E>* currentRow = matrix->get_Element();
        currentRow->go_to_pos(col);
        currentRow->set_element(value);
    }
    int getRows() {
        return rows;
    }
    int getColumns() {
        return columns;
    }
    void addRow(E value) {=
        ArrayList<E>* row = new ArrayList<E>();
        for (int i = 0; i < columns; i++) {
            row->append(value);
        }
        matrix->append(row);
        rows++;
    }
    void addColumn(E value) {
        for (int i = 0; i < rows; i++) {
            matrix->go_to_pos(i);
            ArrayList<E>* row = matrix->get_Element();
            row->append(value);
        }
        columns++;
    }
};
