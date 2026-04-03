#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton instance created." << endl;
    }

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
    Singleton(const Singleton &) = delete;
    void operator=(const Singleton &) = delete;
    void printAddress()
    {
        cout << "Instance Address: " << this << endl;
    }
};

int main()
{
    cout << "Testing Singleton (Single Thread)" << endl;
    cout << "\nGrabbing first instance..." << endl;
    Singleton &instance1 = Singleton::getInstance();
    cout << "Grabbing second instance..." << endl;
    Singleton &instance2 = Singleton::getInstance();
    cout << "Grabbing third instance..." << endl;
    Singleton &instance3 = Singleton::getInstance();
    cout << "\nVerifying Memory Addresses" << endl;
    cout << "Address 1: ";
    instance1.printAddress();
    cout << "Address 2: ";
    instance2.printAddress();
    cout << "Address 3: ";
    instance3.printAddress();
    return 0;
}