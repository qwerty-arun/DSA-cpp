
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    Matrix a11(newSize, vector<int>(newSize));
    Matrix a12(newSize, vector<int>(newSize));
    Matrix a21(newSize, vector<int>(newSize));
    Matrix a22(newSize, vector<int>(newSize));
    Matrix b11(newSize, vector<int>(newSize));
    Matrix b12(newSize, vector<int>(newSize));
    Matrix b21(newSize, vector<int>(newSize));
    Matrix b22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; ++i)
        for (int j = 0; j < newSize; ++j) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }

    Matrix m1 = strassen(add(a11, a22), add(b11, b22));
    Matrix m2 = strassen(add(a21, a22), b11);
    Matrix m3 = strassen(a11, subtract(b12, b22));
    Matrix m4 = strassen(a22, subtract(b21, b11));
    Matrix m5 = strassen(add(a11, a12), b22);
    Matrix m6 = strassen(subtract(a21, a11), add(b11, b12));
    Matrix m7 = strassen(subtract(a12, a22), add(b21, b22));

    Matrix c11 = add(subtract(add(m1, m4), m5), m7);
    Matrix c12 = add(m3, m5);
    Matrix c21 = add(m2, m4);
    Matrix c22 = add(subtract(add(m1, m3), m2), m6);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; ++i)
        for (int j = 0; j < newSize; ++j) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }

    return C;
}

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
}

int main() {
    // Example 4x4 matrices (must be size 2^n x 2^n)
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    Matrix C = strassen(A, B);

    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);
    cout << "\nResult (A x B) using Strassen's Algorithm:\n";
    printMatrix(C);

    return 0;
}
