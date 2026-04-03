#include <iostream>
using namespace std;

template <typename T>
class sparseMatrix
{
private:
    int row;
    int col;
    T *data;

public:
    sparseMatrix(int r, int c)
    {
        row = r;
        col = c;
        data = new T[row * col];
    }
    sparseMatrix(const sparseMatrix &other)
    {
        row = other.row;
        col = other.col;
        data = new T[row * col];
        for (int i = 0; i < row * col; i++)
        {
            data[i] = other.data[i];
        }
    }
    sparseMatrix &operator=(const sparseMatrix &other)
    {
        if (this != &other)
        {
            delete[] data;
            row = other.row;
            col = other.col;
            data = new T[row * col];
            for (int i = 0; i < row * col; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~sparseMatrix()
    {
        delete[] data;
    }

    void input()
    {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> data[i * col + j];
            }
        }
    }

    sparseMatrix add(sparseMatrix &other)
    {
        if (row != other.row || col != other.col)
        {
            throw "Matrices dimensions do not match for addition.";
        }
        sparseMatrix result(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.data[i * col + j] = data[i * col + j] + other.data[i * col + j];
            }
        }
        return result;
    }

    sparseMatrix subtract(sparseMatrix &other)
    {
        if (row != other.row || col != other.col)
        {
            throw "Matrices dimensions do not match for subtraction.";
        }
        sparseMatrix result(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.data[i * col + j] = data[i * col + j] - other.data[i * col + j];
            }
        }
        return result;
    }

    sparseMatrix multiply(sparseMatrix &other)
    {
        if (col != other.row)
        {
            throw "Matrices dimensions do not match for multiplication.";
        }
        sparseMatrix result(row, other.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                result.data[i * other.col + j] = 0;
                for (int k = 0; k < col; k++)
                {
                    result.data[i * other.col + j] += data[i * col + k] * other.data[k * other.col + j];
                }
            }
        }
        return result;
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << data[i * col + j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    sparseMatrix<int> mat1(r1, c1);
    mat1.input();

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    sparseMatrix<int> mat2(r2, c2);
    mat2.input();

    cout << "\n\n"
         << endl;

    try
    {
        sparseMatrix<int> sum = mat1.add(mat2);
        cout << "Sum of matrices:" << endl;
        sum.display();
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    cout << "\n\n"
         << endl;

    try
    {
        sparseMatrix<int> diff = mat1.subtract(mat2);
        cout << "Difference of matrices:" << endl;
        diff.display();
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    cout << "\n\n"
         << endl;

    try
    {
        sparseMatrix<int> prod = mat1.multiply(mat2);
        cout << "Product of matrices:" << endl;
        prod.display();
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}