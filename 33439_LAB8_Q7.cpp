#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class outOfBoundsException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "ERROR : Out Of Bounds! Field doesn't exist.";
    }
};

class incompDimException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "ERROR : Incompatible Dimensions!";
    }
};

class Matrix
{
private:
    int row, col;
    vector<int> data;

public:
    Matrix(int r, int c) : row(r), col(c), data(r * c)
    {
        if (r <= 0 || c <= 0)
            throw invalid_argument("ERROR : Row and Column must be positive integers.");
    }
    ~Matrix()
    {
    }
    void input()
    {
        cout << "Enter elements  : " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> data[i * col + j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << data[i * col + j] << '\t';
            }
            cout << endl;
        }
    }
    void setValue(int r, int c, double val)
    {
        if (r < 0 || r >= row || c < 0 || c >= col)
            throw outOfBoundsException();
        data[r * col + c] = val;
    }

    Matrix addMatrices(Matrix &other)
    {
        if (this->row != other.row || this->col != other.col)
            throw incompDimException();
        Matrix res(row, col);
        for (int i = 0; i < row * col; i++)
        {
            res.data[i] = this->data[i] + other.data[i];
        }
        return res;
    }

    Matrix multiplyMatrices(Matrix &other)
    {
        if (this->col != other.row)
            throw incompDimException();
        Matrix res(this->row, other.col);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                double sum = 0;

                for (int k = 0; k < this->col; k++)
                {
                    sum += this->data[i * this->col + k] * other.data[k * other.col + j];
                }
                res.data[i * other.col + j] = sum;
            }
        }
        return res;
    }
};

int main()
{
    try
    {
        cout << "Creating Matrices." << endl;
        Matrix m1(2, 2);
        Matrix m2(2, 2);
        m1.setValue(0, 0, 1);
        m1.setValue(0, 1, 2);
        m1.setValue(1, 0, 3);
        m1.setValue(1, 1, 4);
        m2.setValue(0, 0, 5);
        m2.setValue(0, 1, 6);
        m2.setValue(1, 0, 7);
        m2.setValue(1, 1, 8);
        cout << "\nMatrix 1:" << endl;
        m1.display();
        cout << "\nMatrix 2:" << endl;
        m2.display();
        cout << "\nTesting Addition." << endl;
        Matrix sum = m1.addMatrices(m2);
        sum.display();
        cout << "\nTesting Multiplication." << endl;
        Matrix product = m1.multiplyMatrices(m2);
        product.display();
        cout << "\nTriggering Out of Bounds Exception." << endl;
        m1.setValue(5, 5, 99);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "\nTriggering Incompatible Dimensions Exception." << endl;
        Matrix A(2, 2);
        Matrix B(3, 3);
        Matrix C = A.addMatrices(B);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}