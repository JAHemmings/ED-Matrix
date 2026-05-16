//Profe me di cuenta que le puse Matriz.h al otro en lugar de Matrix.h y tambien le adelanto que transpose no me funciona

#pragma once

#include <iostream>
#include <stdexcept>
#include "ArrayList.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Matrix {
private:
    ArrayList<ArrayList<E>*>* matrix;
    int rows;
    int columns;
    void validate(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= columns)
            throw runtime_error("Indice no existe");
    }

public:
    Matrix(int rows, int columns) {
        if (rows <= 0 || columns <= 0)
            throw runtime_error("Dimensiones invalidas");
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
        matrix->goToStart();
        for (int i = 0; i < rows; i++) {
            ArrayList<E>* row = matrix->getElement();
            delete row;
            matrix->next();
        }
        delete matrix;
    }

    E getValue(int row, int col) {
        validate(row, col);
        matrix->goToPos(row);
        ArrayList<E>* currentRow = matrix->getElement();
        currentRow->goToPos(col);
        return currentRow->getElement();
    }

    void setValue(int row, int col, E value) {
        validate(row, col);
        matrix->goToPos(row);
        ArrayList<E>* currentRow = matrix->getElement();
        currentRow->goToPos(col);
        currentRow->setElement(value);
    }

    int getRows() {
        return rows;
    }

    int getColumns() {
        return columns;
    }

    void setAll(E value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                setValue(i, j, value);
            }
        }
    }

    void transpose() {
        Matrix<E>* temp = new Matrix<E>(columns, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                temp->setValue(j, i, getValue(i, j));
            }
        }
        for (int i = 0; i < rows; i++) {
            matrix->goToPos(i);
            delete matrix->getElement();
        }
        delete matrix;
        matrix = temp->matrix;
        rows = temp->rows;
        columns = temp->columns;
        temp->matrix = nullptr;
        delete temp;
    }

    void addRow(E value) {
        ArrayList<E>* row = new ArrayList<E>();
        for (int i = 0; i < columns; i++) {
            row->append(value);
        }
        matrix->append(row);
        rows++;
    }

    void addColumn(E value) {
        for (int i = 0; i < rows; i++) {
            matrix->goToPos(i);
            ArrayList<E>* row = matrix->getElement();
            row->append(value);
        }
        columns++;
    }

    void removeRow(int row) {
        if (row < 0 || row >= rows)
            throw runtime_error("Fila Invalida");
        matrix->goToPos(row);
        ArrayList<E>* deletedRow = matrix->remove();
        delete deletedRow;
        rows--;
    }

    void removeColumn(int col) {
        if (col < 0 || col >= columns)
            throw runtime_error("Columna Invalida");
        for (int i = 0; i < rows; i++) {
            matrix->goToPos(i);
            ArrayList<E>* row = matrix->getElement();
            row->goToPos(col);
            row->remove();
        }
        columns--;
    }

    void print() {
        cout << endl;
        for (int i = 0; i < rows; i++) {
            cout << "[";
            for (int j = 0; j < columns; j++) {
                cout << getValue(i, j);
                if (j< columns-1)
                    cout << ",";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
};
