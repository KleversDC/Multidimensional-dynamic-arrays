#include <iostream>
using namespace std;
//1
//void AddColumn(int**& matrix, int& rows, int& cols, int* newCol, int position) {
//    int** newMatrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        newMatrix[i] = new int[cols + 1];
//        int colIndex = 0;
//        for (int j = 0; j < position; j++) {
//            newMatrix[i][colIndex++] = matrix[i][j];
//        }
//        newMatrix[i][colIndex++] = newCol[i];
//        for (int j = position; j < cols; j++) {
//            newMatrix[i][colIndex++] = matrix[i][j];
//        }
//    }
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    matrix = newMatrix;
//    cols++;
//}
//int main() {
//    int rows = 3, cols = 3;
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = i * cols + j + 1;
//        }
//    }
//    int newCol[] = { 10, 20, 30 };
//    AddColumn(matrix, rows, cols, newCol, 1);
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//2
//void RemoveColumn(int**& matrix, int& rows, int& cols, int position) {
//    int** newMatrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        newMatrix[i] = new int[cols - 1];
//        int colIndex = 0;
//        for (int j = 0; j < cols; j++) {
//            if (j != position) {
//                newMatrix[i][colIndex++] = matrix[i][j];
//            }
//        }
//    }
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    matrix = newMatrix;
//    cols--;
//}
//int main() {
//    int rows = 3, cols = 3;
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = i * cols + j + 1;
//        }
//    }
//    RemoveColumn(matrix, rows, cols, 1);
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//3
void ShiftRow(int* row, int cols, int shift) {
    int* temp = new int[cols];
    for (int i = 0; i < cols; i++) {
        temp[(i + shift) % cols] = row[i];
    }
    for (int i = 0; i < cols; i++) {
        row[i] = temp[i];
    }

    delete[] temp;
}
void ShiftColumn(int** matrix, int rows, int col, int shift) {
    int* temp = new int[rows];
    for (int i = 0; i < rows; i++) {
        temp[(i + shift) % rows] = matrix[i][col];
    }
    for (int i = 0; i < rows; i++) {
        matrix[i][col] = temp[i];
    }

    delete[] temp;
}
void ShiftMatrix(int** matrix, int rows, int cols, int shiftRows, int shiftCols) {
    for (int i = 0; i < rows; i++) {
        ShiftRow(matrix[i], cols, shiftRows);
    }
    for (int j = 0; j < cols; j++) {
        ShiftColumn(matrix, rows, j, shiftCols);
    }
}
int main() {
    int rows = 3, cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    cout << "Initial matrix :" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    ShiftMatrix(matrix, rows, cols, 1, 1);
    cout << "The matrix after the shift:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

