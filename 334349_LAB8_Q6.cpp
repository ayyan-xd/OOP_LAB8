#include <iostream>
#include <vector>
using namespace std;

class Logger
{
public:
    virtual void logMessage(string message) = 0;
};

class ConsoleLogger : public Logger
{
public:
    void logMessage(string message) override
    {
        cout << "LOG : " << message << endl;
    }
};

class FileLogger : public Logger
{
public:
    void logMessage(string message) override
    {
        cout << "LOG : " << message << endl;
    }
};

class DataBaseLogger : public Logger
{
public:
    void logMessage(string message) override
    {
        cout << "LOG : " << message << endl;
    }
};

int main()
{
    ConsoleLogger console;
    FileLogger file;
    DataBaseLogger db;
    cout << "\nBroadcasting Log Messages." << endl;
    console.logMessage("User 'Admin' successfully logged in.");
    file.logMessage("Appending to System Log.");
    db.logMessage("Inserting record into 'Logs'.");
    return 0;
}