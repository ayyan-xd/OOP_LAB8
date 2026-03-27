#include <iostream>
using namespace std;

class Shape{
    public :
    virtual double area() = 0;
virtual ~Shape() {}
};

class Circle : public Shape {
    private :
    double radius;
    public :
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private :
double length, width;
public :
Rectangle(double l, double w) : length(l), width(w) {}
double area () override {
    return length * width;
    }
};

class Triangle : public Shape {
private :
double base, height;
public :
Triangle(double b, double h) : base(b), height(h) {}
double area() override {
    return 0.5 * base * height;
}
    };
int main() {
    Circle C(5.5);
    Rectangle R(8, 4.2);
    Triangle T(6, 3.5);
    Shape* shapes[] = {&C, &R, &T};
    cout << "Area Calculator : " << endl;
    for (int i=0 ; i<3 ; i++) {
        cout << "Area of shape " << i+1 << " : " << shapes[i]->area() << endl;
    }
    return 0;
}