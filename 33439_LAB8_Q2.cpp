#include <iostream>
#include <iomanip>
using namespace std;

class Account {
    protected :
    double balance;
    double interestRate;
    int time;
    public :
    Account(double b, double r, int t) : balance(b), interestRate(r), time(t) {}
  virtual double calculateInterest() = 0; 
  virtual ~Account() {}
};

class SavingsAccount : public Account {
    public :
    SavingsAccount(double b, double r, int t) : Account(b, r, t) {}
    double calculateInterest() override {
        return ((balance * interestRate * time) / 12.0);
    }
};

class CheckingAccount : public Account {
    private :
    double fee;
    public :
    CheckingAccount(double b, double r, int t, double f) : Account(b, r, t), fee(f) {}
    double calculateInterest() override {
        return (((balance - fee) * interestRate * time) / 12.0);
    }
};
int main() {
    cout << fixed << setprecision(2);
    SavingsAccount savings(5000.0, 0.03, 6);
    CheckingAccount checking(3000.0, 0.015, 6, 100.0);
    Account* acc1 = &savings;
    Account* acc2 = &checking;
    cout << "Savings Account Interest: $" << acc1->calculateInterest() << endl;
    cout << "Checking Account Interest: $" << acc2->calculateInterest() << endl;
return 0;
}