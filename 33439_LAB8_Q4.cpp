#include <iostream>
#include <string>
#include <exception>
using namespace std;

class FileNotFoundException : public exception {
public :
    const char* what() const noexcept override {
        return "ERROR : File not found.";
    }
};

class FilePermissionException : public exception {
public :
    const char* what() const noexcept override {
        return "ERROR : Permission Denied. Cannot access file.";
    }
};

class FileHandler {
private :
    bool isOpen = false;
    string opennedFileName = " ";
public :
void openFile(const string& fileName) {
    cout << "Openning '" << fileName << "'." << endl;
    if (fileName == "notFound.txt") throw FileNotFoundException();
    if (fileName == "notAllowed.txt") throw FilePermissionException();
    isOpen = true;
    opennedFileName = fileName;
    cout << "File '" << opennedFileName << "' Openned!" << endl;
}
void readFromFile(const string& fileName) {
    if (!isOpen) throw FilePermissionException();
    cout << "Read from file '" << opennedFileName << "'!" << endl;
}
void writeToFile(const string& text) {
        if (!isOpen) throw FilePermissionException();
        cout << "Wrote data to file '" << opennedFileName << "'!" << endl;
    }
void closeFile() {
    if (isOpen) {
        isOpen = false;
        cout << "File '" << opennedFileName << "' closed!" << endl;
        }
    }
};

int main() {
    FileHandler myFiles;
    try {
        cout << "FILE NOT FOUND CASE : " << endl;
        myFiles.openFile("notFound.txt");
    }
    catch(const exception& e) {
        cout << e.what() << endl << endl;
    }
    try {
        cout << "PERMISSION NOT GRANTED CASE : " << endl;
        myFiles.openFile("notAllowed.txt");
    }
    catch(const exception& e) {
        cout << e.what() << endl << endl;
    }
    try {
        cout << "VALID FILE CASE : " << endl;
        myFiles.openFile("LAB8.cpp");
        myFiles.writeToFile("ERP : 33439");
        myFiles.closeFile();
    }
    catch(const exception& e) {
        cout << e.what() << endl << endl;

    }
}
