#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T, typename PriorityFunc>
class PriorityQueue
{
private:
    std::priority_queue<T, std::vector<T>, PriorityFunc> pq;

public:
    void insert(const T &element)
    {
        pq.push(element);
    }
    T getHighestPriority()
    {
        if (pq.empty())
        {
            throw runtime_error("Queue is empty!");
        }
        T topElement = pq.top();
        pq.pop();

        return topElement;
    }
};
struct SmallestFirst
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    cout << "Testing Custom Priority Queue." << endl;
    cout << "Rule: Smallest numbers get served first!\n"
         << endl;
    PriorityQueue<int, SmallestFirst> myQueue;
    cout << "Inserting: 50, 10, 30, 5..." << endl;
    myQueue.insert(50);
    myQueue.insert(10);
    myQueue.insert(30);
    myQueue.insert(5);
    cout << "\nPulling from the Queue." << endl;
    try
    {
        cout << "First pulled: " << myQueue.getHighestPriority() << endl;
        cout << "Second pulled: " << myQueue.getHighestPriority() << endl;
        cout << "Third pulled: " << myQueue.getHighestPriority() << endl;
        cout << "Fourth pulled: " << myQueue.getHighestPriority() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}