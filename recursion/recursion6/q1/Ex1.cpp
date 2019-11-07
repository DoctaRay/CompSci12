#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void triangle(int x, int y, string stars) {
    if (stars.length() < y) {
        stars+='*';
        if(stars.length()<y)cout << stars << endl;
            triangle(x, y, stars);
    }
    cout << stars << endl;

    // if (reverse) {
    //     if (x == count) {
    //         cout << string(x, star);
    //         return;
    //     }
    //     cout << string(x, star) << endl;
    //     x--;
    //     triangle(x, y, reverse);
    // }
    // else if (x == y) {
    //     reverse = true;
    //     cout << string(x, star) << endl;
    //     x--;
    //     triangle(x, y, reverse);
    // }
    // cout << string(x, star) << endl;
    // x++;
    // triangle(x, y);
    // if (count == 0) {
    //     count = x;
    // }
    // if (reverse) {
    //     cout << string(count, star) << endl;
    //     count--;
    //     triangle(x, y, count, reverse);
    //     if (count == x) {
    //         return;
    //     }
    // }
    // else if (count < y) {
    //     cout << string(count, star) << endl;
    //     count++;
    //     triangle(x, y, count);
    // }
    // else if (count == y) {
    //     reverse = true;
    //     cout << string(count, star) << endl;
    //     triangle(x, y, count, reverse);
    // }


}

int main() {
    int x, y;
    cout << "Enter smaller number: ";
    cin >> x;
    cout << "Enter larger number: ";
    cin >> y;

    string stars;

    for (int i = x; i < y; i++) {
        stars+='*';
    }

    triangle(x, y, stars);
}