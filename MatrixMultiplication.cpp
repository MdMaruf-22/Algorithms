#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> matrixAddition(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrixSubtraction(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
vector<vector<int>> strassenMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }
    int half_size = n / 2;
    vector<vector<int>> a11(half_size, vector<int>(half_size));
    vector<vector<int>> a12(half_size, vector<int>(half_size));
    vector<vector<int>> a21(half_size, vector<int>(half_size));
    vector<vector<int>> a22(half_size, vector<int>(half_size));
    vector<vector<int>> b11(half_size, vector<int>(half_size));
    vector<vector<int>> b12(half_size, vector<int>(half_size));
    vector<vector<int>> b21(half_size, vector<int>(half_size));
    vector<vector<int>> b22(half_size, vector<int>(half_size));
    for (int i = 0; i < half_size; ++i)
    {
        for (int j = 0; j < half_size; ++j)
        {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + half_size];
            a21[i][j] = A[i + half_size][j];
            a22[i][j] = A[i + half_size][j + half_size];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + half_size];
            b21[i][j] = B[i + half_size][j];
            b22[i][j] = B[i + half_size][j + half_size];
        }
    }
    vector<vector<int>> p1 = strassenMatrixMultiply(matrixAddition(a11, a22), matrixAddition(b11, b22));
    vector<vector<int>> p2 = strassenMatrixMultiply(matrixAddition(a21, a22), b11);
    vector<vector<int>> p3 = strassenMatrixMultiply(a11, matrixSubtraction(b12, b22));
    vector<vector<int>> p4 = strassenMatrixMultiply(a22, matrixSubtraction(b21, b11));
    vector<vector<int>> p5 = strassenMatrixMultiply(matrixAddition(a11, a12), b22);
    vector<vector<int>> p6 = strassenMatrixMultiply(matrixSubtraction(a21, a11), matrixAddition(b11, b12));
    vector<vector<int>> p7 = strassenMatrixMultiply(matrixSubtraction(a12, a22), matrixAddition(b21, b22));
    vector<vector<int>> c11 = matrixSubtraction(matrixAddition(matrixAddition(p1, p4), p7), p5);
    vector<vector<int>> c12 = matrixAddition(p3, p5);
    vector<vector<int>> c21 = matrixAddition(p2, p4);
    vector<vector<int>> c22 = matrixSubtraction(matrixAddition(matrixSubtraction(p1, p2), p3), p6);
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < half_size; ++i)
    {
        for (int j = 0; j < half_size; ++j)
        {
            C[i][j] = c11[i][j];
            C[i][j + half_size] = c12[i][j];
            C[i + half_size][j] = c21[i][j];
            C[i + half_size][j + half_size] = c22[i][j];
        }
    }
    return C;
}
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the dimension of the matrices: ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }
    vector<vector<int>> result = strassenMatrixMultiply(A, B);
    cout << "Resultant matrix:" << endl;
    printMatrix(result);

    return 0;
}
