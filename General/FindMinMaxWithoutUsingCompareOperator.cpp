/*
You want to find the minimum and maximum between two numbers without using comparison operators like <, >, <=, >=, right?
Here’s the idea:
We can use math operations like addition, subtraction, and absolute value.

✅ Here’s the trick:
For two numbers a and b:

Minimum = (a + b - abs(a - b)) / 2
Maximum = (a + b + abs(a - b)) / 2

*/

#include <iostream>
#include <cmath>  // for abs
using namespace std;

int main() {
    int a = 5, b = 8;

    int minimum = (a + b - abs(a - b)) / 2;
    int maximum = (a + b + abs(a - b)) / 2;

    cout << "Minimum is: " << minimum << endl;
    cout << "Maximum is: " << maximum << endl;

    return 0;
}
