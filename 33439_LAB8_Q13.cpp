#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class stack
{
private:
    T *arr;
    int topIdx;
    int capacity;

public:
    stack(int size)
    {
        arr = new T[size];
        capacity = size;
        topIdx = -1;
    }
    ~stack()
    {
        delete[] arr;
    }

    void push(T x)
    {
        if (topIdx == capacity - 1)
        {
            throw overflow_error("Stack overflow");
        }
        arr[++topIdx] = x;
    }

    T pop()
    {
        if (topIdx == -1)
        {
            throw underflow_error("Stack underflow");
        }
        return arr[topIdx--];
    }
    T top()
    {
        if (topIdx == -1)
        {
            throw runtime_error("Stack is empty");
        }
        return arr[topIdx];
    }
};
int main()
{
    stack<int> s(5);
    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        cout << "Top element: " << s.top() << endl;
        cout << "Popped element: " << s.pop() << endl;
        cout << "Top element after pop: " << s.top() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}