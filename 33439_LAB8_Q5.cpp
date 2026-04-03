#include <iostream>
#include <exception>
using namespace std;

class negativeAgeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "ERROR : Age cannot be negative.";
    }
};

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a)
    {
        if (a < 0)
            throw negativeAgeException();
        cout << "Person Constructor Called." << endl;
    }
    virtual void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
    virtual string getRole()
    {
        return "Person";
    }
    virtual ~Person()
    {
        cout << "Person Destructor Called." << endl;
    }
};

class Student : virtual public Person
{
public:
    Student(string n, int a) : Person(n, a)
    {
        cout << "Student Constructer Called." << endl;
    }
    void display() override
    {
        Person ::display();
    }
    string getRole() override
    {
        return "Student";
    }
    ~Student()
    {
        cout << "Student Destructor Called." << endl;
    }
};

class Employee : virtual public Person
{
public:
    Employee(string n, int a) : Person(n, a)
    {
        cout << "Employee Constructor Called." << endl;
    }
    void display() override
    {
        Person::display();
    }
    string getRole() override
    {
        return "Employee";
    }
    ~Employee()
    {
        cout << "Employee Destructor Called." << endl;
    }
};

class TeachingAssistant : public Student, public Employee
{
public:
    TeachingAssistant(string n, int a) : Person(n, a), Student(n, a), Employee(n, a)
    {
        cout << "Teaching Assistant Constructor Called." << endl;
    }
    void display() override
    {
        Person::display();
    }
    string getRole() override
    {
        return "Teaching Assistant.";
    }
    ~TeachingAssistant() override
    {
        cout << "TeachingAssistant Destructor called." << endl;
    }
};

void testDiamondProblem()
{
    cout << "->Testing Constructor Execution Order." << endl;
    try
    {
        TeachingAssistant TA("Bob", 22); // enter negative age for negative age exception and postive for other ecxptions demonstration.
        cout << "\n->Demonstrating Polymorphism via Base Class Pointer." << endl;
        Person *ptr = &TA;
        ptr->display();
        cout << "\n->Directly calling getRole() via Base class pointer." << endl
             << ptr->getRole() << endl;
        cout << "\n->Testing Destructor Order." << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    testDiamondProblem();
    return 0;
}