#include <iostream>
#include <exception>
#include <limits>
using namespace std;

class DivisionByZeroException : public exception {
public :
    const char* what() const noexcept override {
        return "ERROR : Division by Zero not allowed.";
    }
};

double performDivision(double numerator, double denominator) {
    if (denominator == 0) {
        throw DivisionByZeroException();
    }
    if (denominator < 0) {
        cout << "WARNING : Converting negative denominator to positive." << endl;
        denominator = -denominator;
    }
    return numerator / denominator;
}

int main() {
    char choice;
    do {
        double num, den;
        cout << "Enter numerator: ";
        while (!(cin >> num)) {
            cout << "Invalid input. Please enter a number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter denominator: ";
        while (!(cin >> den)) {
            cout << "Invalid input. Please enter a number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        try {
            double result = performDivision(num, den);
            cout << "Result : " << result << endl;
        } 
        catch(const DivisionByZeroException &e) {
            cout << e.what() << endl;
        }
        cout << "\nDo you want to perform another division? (y/n) : ";
        cin >> choice;
    } 
    while (choice == 'y' || choice == 'Y');
    return 0;
}
