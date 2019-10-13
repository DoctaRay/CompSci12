#include<iostream>
#include<string>

using namespace std;

int gcf(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcf(y, x % y);
}

int main() {
    int x;
    int y;
    int max;
    cout << "Enter first number (highest number): ";
    cin >> x;
    cout << "\nEnter second number (lowest number): ";
    cin >> y;

    if (x > y) max = x;
    else max = y;

    cout << "GCF is " << gcf(x, y);
}