#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename BinaryOperation>
vector<vector<T>> matrix_operation(
    const vector<vector<T>> &m1,
    const vector<vector<T>> &m2,
    size_t rows, size_t cols,
    BinaryOperation op)
{
    vector<vector<T>> result(rows, vector<T>(cols));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            result[i][j] = op(m1[i][j], m2[i][j]);
        }
    }
    return result;
}

int main()
{
    size_t rows = 2;
    size_t cols = 2;
    vector<vector<int>> matrixA = {
        {1, 2},
        {3, 4}};
    vector<vector<int>> matrixB = {
        {5, 6},
        {7, 8}};
    auto add = [](const auto &a, const auto &b)
    {
        return a + b;
    };
    vector<vector<int>> resultMatrix = matrix_operation(matrixA, matrixB, rows, cols, add);
    cout << "Result of Element-wise Addition:" << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << resultMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}