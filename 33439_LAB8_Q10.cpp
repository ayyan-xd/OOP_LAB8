#include <iostream>
#include <string>
using namespace std;
template <typename T>
void swap_values(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 5, y = 10;
    swap_values(x, y);
    cout << x << " " << y << endl;
    string s1 = "First", s2 = "Second";
    swap_values(s1, s2);
    cout << s1 << " " << s2 << endl;
    return 0;
}