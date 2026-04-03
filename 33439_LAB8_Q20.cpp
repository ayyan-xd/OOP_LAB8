#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class TestObject
{
public:
    long long data[4];
};
class SimpleMemoryPool
{
private:
    TestObject *pool;
    TestObject **freeList;
    int topIndex;

public:
    SimpleMemoryPool(int size)
    {
        pool = new TestObject[size];
        freeList = new TestObject *[size];
        for (int i = 0; i < size; i++)
        {
            freeList[i] = &pool[i];
        }
        topIndex = size - 1;
    }

    ~SimpleMemoryPool()
    {
        delete[] freeList;
        delete[] pool;
    }
    TestObject *allocate()
    {
        if (topIndex < 0)
        {
            cout << "Pool is empty!" << endl;
            return nullptr;
        }
        return freeList[topIndex--];
    }
    void deallocate(TestObject *obj)
    {
        freeList[++topIndex] = obj;
    }
};

int main()
{
    const int ALLOCATIONS = 100000;
    TestObject *arr[ALLOCATIONS];
    cout << "=== Memory Allocation Performance Test ===" << endl;
    cout << "Testing " << ALLOCATIONS << " allocations and deallocations...\n"
         << endl;
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        arr[i] = new TestObject();
    }
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        delete arr[i];
    }
    auto stop1 = high_resolution_clock::now(); // Stop stopwatch
    auto duration1 = duration_cast<microseconds>(stop1 - start1).count();
    SimpleMemoryPool myPool(ALLOCATIONS);
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        arr[i] = myPool.allocate();
    }
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        myPool.deallocate(arr[i]);
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2).count();
    cout << "Standard new/delete took : " << duration1 << " microseconds." << endl;
    cout << "Memory Pool took         : " << duration2 << " microseconds." << endl;
    if (duration2 < duration1)
    {
        cout << "\n-> SUCCESS: The Memory Pool was faster!" << endl;
    }
    return 0;
}