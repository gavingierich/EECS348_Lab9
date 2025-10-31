
// Gavin Gierich
// 10/30/2025
// This program performs matrix operations for the user


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

using Matrix = vector<vector<int>>;

// Function Declarations
Matrix readMatrix(ifstream& fin, int N);
void printMatrix(const Matrix& matrix);
Matrix addMatrices(const Matrix& A, const Matrix& B);
Matrix multiplyMatrices(const Matrix& A, const Matrix& B);
void sumDiagonal(const Matrix& M);
void swapRows(Matrix& M, int r1, int r2);
void swapCols(Matrix& M, int col1, int col2);
void updateElement(Matrix& M, int r, int c, int val);

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    int N;
    fin >> N;

    Matrix A = readMatrix(fin, N);
    Matrix B = readMatrix(fin, N);

    fin.close();

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "\nMatrix B:\n"; printMatrix(B);

    bool running = true;

    while (running) {

        string choice;
        cout << "\n---------- Menu ----------";
        cout << "\n1) Print Matrices\n2) Add Matrices\n3) Multiply Matrices\n4) Get sum of diagonals\n5) Swap rows\n6) Swap columns\n7) Update Matrix\n8) Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        cout << "\n";
        
        if (choice == "1") {
            cout << "Matrix A:\n"; printMatrix(A);
            cout << "\nMatrix B:\n"; printMatrix(B);
        }
        else if (choice == "2") {
            cout << "Added Matrices:\n"; printMatrix(addMatrices(A, B));
        }
        else if (choice == "3") {
            cout << "Multiplied Matrices:\n"; printMatrix(multiplyMatrices(A, B));
        }
        else if (choice == "4") {
            string mat;
            cout << "1) Matrix A\n2) Matrix B\nEnter choice: ";
            cin >> mat;
            
            if (mat == "1") {
                sumDiagonal(A);
            }
            else if (mat == "2") {
                sumDiagonal(B);
            }
            else {
                cout << "Invalid choice\n";
            }
        }
        else if (choice == "5") {
            int r1, r2;
            cout << "Enter two row indices to swap(0 1): ";
            cin >> r1 >> r2;

            string mat;
            cout << "1) Matrix A\n2) Matrix B\nEnter choice: ";
            cin >> mat;

            if (mat == "1") {
                swapRows(A, r1, r2);
            }
            else if (mat == "2") {
                swapRows(B, r1, r2);
            }
            else {
                cout << "Invalid choice\n";
            }
        }
        else if (choice == "6") { 
            int c1, c2;
            cout << "Enter two column indices to swap: ";
            cin >> c1 >> c2;

            string mat;
            cout << "1) Matrix A\n2) Matrix B\nEnter choice: ";
            cin >> mat;

            if (mat == "1") {
                swapCols(A, c1, c2);
            }
            else if (mat == "2") {
                swapCols(B, c1, c2);
            }
            else {
                cout << "Invalid choice\n";
            }
        }
        else if (choice == "7") {
            int r, c, val;
            cout << "Enter (row col value): ";
            cin >> r >> c >> val;

            string mat;
            cout << "1) Matrix A\n2) Matrix B\nEnter choice: ";
            cin >> mat;

            if (mat == "1") {
                updateElement(A, r, c, val);
            }
            else if (mat == "2") {
                updateElement(B, r, c, val);
            }
            else {
                cout << "Invalid choice\n";
            }
        }
        else if (choice == "8") {
            cout << "\nClosing Program...";
            running = false;
        }
        else {
            cout << "\nEnter a valid choice";
        }
    }
    return 0;
}


Matrix readMatrix(ifstream& fin, int N) {
    Matrix matrix(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> matrix[i][j];
    return matrix;
}

void printMatrix(const Matrix& matrix) {
    int N = matrix.size();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
}

Matrix addMatrices(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void sumDiagonal(const Matrix& M) {
    int N = M.size();
    int mainDiagonal = 0;
    int secDiagonal = 0;

    for (int i = 0; i < N; i++) {
        mainDiagonal += M[i][i];
        secDiagonal += M[i][N - 1 - i];
    }

    cout << "\nMain Diagonal Sum: " << mainDiagonal;
    cout << "\nSecondary Diagonal Sum: " << secDiagonal;
    cout << "\n";
}

void swapRows(Matrix& M, int r1, int r2) {
    int N = M.size();  // number of rows
    if (r1 >= 0 && r1 < N && r2 >= 0 && r2 < N) {
        swap(M[r1], M[r2]);  // swap the entire rows
        
        printMatrix(M);
    }
    else {
        cout << "Error: One or both row indices are invalid.\n";
    }
}

void swapCols(Matrix& M, int c1, int c2) {
    int N = M.size();  // number of rows = number of columns

    if (c1 >= 0 && c1 < N && c2 >= 0 && c2 < N) {
        for (int i = 0; i < N; ++i)
            swap(M[i][c1], M[i][c2]);

            printMatrix(M);
    }
    else {
        cout << "One or both column indices are invalid.\n";
    }
}

void updateElement(Matrix& M, int r, int c, int val) {
    int N = M.size();

    if (r >= 0 && r < N && c >= 0 && c < N) {
        M[r][c] = val;
        printMatrix(M);
    }
    else {
        cout << "Invalid row or column index\n";
    }
}
