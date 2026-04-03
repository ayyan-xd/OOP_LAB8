#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void enqueue(T x)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }
    T dequeue()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        T x = arr[front];
        front++;
        return x;
    }
    T frontElement()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return arr[front];
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Front element: " << q.frontElement() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element: " << q.frontElement() << endl;
    return 0;
}