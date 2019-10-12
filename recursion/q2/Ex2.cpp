#include<iostream>
#include<string>

using namespace std;

void gcf(int x, int y, int count = 1, int factor int max = 0) {
    if (x % count == 0 && y % count == 0) {
        count++;____
        gcf(x, y, count, max);
    } else if (count == max) {
        cout << "\nGCF is " << count;
    }
}

int main() {
    int x;
    int y;
    int max;
    cout << "Enter first number: ";
    cin >> x;
    cout << "\nEnter second number: ";
    cin >> y;

    if (x > y) max = x;
    else max = y;

    gcf(x, y, 1, max);
}