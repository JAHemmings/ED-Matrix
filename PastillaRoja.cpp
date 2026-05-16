#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main() {
    srand(time(nullptr));
    int rows;
    int columns;
    cout << "Introdusca las filas: ";
    cin >> rows;
    cout << "Introdusca las columnas: ";
    cin >> columns;
    Matrix<int>* matrix = new Matrix<int>(rows, columns);
    int option = -1;
    while (option != 0) {
        cout << endl;

        matrix->print();
        cout << "1. Obtener valor" << endl;
        cout << "2. Cambiar valor" << endl;
        cout << "3. Obtener filas" << endl;
        cout << "4. Obtener columnas" << endl;
        cout << "5. Asignar valor" << endl;
        cout << "6. Trasponer" << endl;
        cout << "7. Anadir Fila" << endl;
        cout << "8. Anadir Columna" << endl;
        cout << "9. Eliminar Fila" << endl;
        cout << "10. Eliminar Columna" << endl;
        cout << "11. Cargar valores" << endl;
        cout << "0. Salir" << endl;
        cout << "Opciones: ";
        cin >> option;

        try {
            if (option == 1) {
                int row, col;
                cout << "Fila: ";
                cin >> row;
                cout << "Columna: ";
                cin >> col;
                cout << "Valor: "<< matrix->getValue(row, col) << endl;
            }
            else if (option == 2) {
                int row, col, value;
                cout << "Fila: ";
                cin >> row;
                cout << "Columna: ";
                cin >> col;
                cout << "Valor: ";
                cin >> value;
                matrix->setValue(row, col, value);
            }

            else if (option == 3) {
                cout << "Fila: "
                    << matrix->getRows() << endl;
            }

            else if (option == 4) {
                cout << "Columna: "
                    << matrix->getColumns() << endl;
            }

            else if (option == 5) {
                int value;
                cout << "Valor: ";
                cin >> value;
                matrix->setAll(value);
            }
            else if (option == 6) {
                matrix->transpose();
            }

            else if (option == 7) {
                int value;
                cout << "Valores para la nueva Fila: ";
                cin >> value;
                matrix->addRow(value);
            }

            else if (option == 8) {
                int value;
                cout << "Valores para la nueva Columna: ";
                cin >> value;
                matrix->addColumn(value);
            }

            else if (option == 9) {
                int row;
                cout << "Fila a remover: ";
                cin >> row;
                matrix->removeRow(row);
            }
            else if (option == 10) {
                int col;
                cout << "Columna a remover: ";
                cin >> col;
                matrix->removeColumn(col);
            }

            else if (option == 11) {
                for (int i = 0; i < matrix->getRows(); i++) {
                    for (int j = 0; j < matrix->getColumns(); j++) {
                        matrix->setValue(i, j, rand() % 100);
                    }
                }
            }
            else if (option == 0) {
                cout << "Saliendo" << endl;
            }
            else {
                cout << "Opcion invalida" << endl;
            }
        }
        catch (runtime_error& e) {
            cout << "ERROR: No se digito algo valido" << endl;
        }
    }
    delete matrix;
    return 0;
}