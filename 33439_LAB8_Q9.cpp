#include <iostream>
using namespace std;
template <typename T>
T max_value(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}
int main() {
    cout << max_value(10, 50, 30) << endl;
    cout << max_value(4.5, 2.1, 9.8) << endl;
    cout << max_value('a', 'x', 'c') << endl;
    return 0;
}