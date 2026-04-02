#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

class FileNotFoundException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "ERROR : File not found.";
    }
};

class FilePermissionException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "ERROR : Permission Denied. Cannot access file.";
    }
};

class FileHandler
{
private:
    fstream file;
    string openedFileName = " ";

public:
    void openFile(const string &fileName)
    {
        cout << "Opening '" << fileName << "'." << endl;
        file.open(fileName, ios::in | ios::out);
        if (!file.is_open())
        {
            file.clear();
            file.open(fileName, ios::in | ios::out | ios::trunc);
        }
        if (!file.is_open())
        {
            throw FilePermissionException();
        }
        openedFileName = fileName;
        cout << "File '" << openedFileName << "' Opened!" << endl;
    }

    void writeToFile(const string &text)
    {
        if (!file.is_open())
            throw FilePermissionException();
        file << text << endl;
        cout << "Wrote data to file." << endl;
    }

    void readFromFile()
    {
        if (!file.is_open())
            throw FilePermissionException();
        file.clear();
        file.seekg(0);
        string line;
        cout << "Reading from file '" << openedFileName << "'." << endl;
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }

    void closeFile()
    {
        if (file.is_open())
        {
            file.close();
            cout << "File '" << openedFileName << "' closed!" << endl;
        }
    }

    ~FileHandler()
    {
        closeFile();
    }
};

int main()
{
    FileHandler fileHandler;
    string filename = "testFile.txt";

    try
    {
        fileHandler.openFile(filename);
        fileHandler.writeToFile("Testing file handling.");
        fileHandler.writeToFile("Did it work?.");
        fileHandler.readFromFile();
        fileHandler.closeFile();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
