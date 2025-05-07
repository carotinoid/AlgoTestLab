#ifndef MULTIPLICATION_HH
#define MULTIPLICATION_HH

long long integer_multiplication(long long a, long long b);

struct Matrix {
    long long *data;
    int rows, cols;
    Matrix(int r, int c) : rows(r), cols(c) { data = new long long[r * c]; }
    ~Matrix() { delete[] data; }
    long long &operator()(int i, int j) { return data[i * cols + j]; }
    long long operator()(int i, int j) const { return data[i * cols + j]; }
};

Matrix matrix_multiplication(const Matrix &A, const Matrix &B);

#endif  // MULTIPLICATION_HH