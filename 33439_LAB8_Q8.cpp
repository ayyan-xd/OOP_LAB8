#include <iostream>
#include <string>
using namespace std;

class PoweredSystem
{
public:
    PoweredSystem()
    {
        cout << "Powered Syestem Constructor Called." << endl;
    }
    ~PoweredSystem()
    {
        cout << "Powered Syestem Destructor Called." << endl;
    }
};

class Veicle : virtual public PoweredSystem
{
public:
    Veicle()
    {
        cout << "Veicle Constructor Called." << endl;
    }
    ~Veicle()
    {
        cout << "Veicle Destructor Called." << endl;
    }
};

class Engine : virtual public PoweredSystem
{
public:
    Engine()
    {
        cout << "Engine Constructor Called." << endl;
    }
    ~Engine()
    {
        cout << "Engine Destructor Called." << endl;
    }
};

class Car : public Veicle, public Engine
{
public:
    Car()
    {
        cout << "Car Constructor Called." << endl;
    }
    ~Car()
    {
        cout << "Car Destructor Called." << endl;
    }
};

void testDiamondProblem()
{
    cout << "->Testing Constructor Execution Order." << endl;
    Car myCar;
    cout << "\n->Testing Destructor Execution Order." << endl;
}

int main()
{
    cout << "Demonstrating the Diamond Problem in C++." << endl << endl;
    testDiamondProblem();
    return 0;
}