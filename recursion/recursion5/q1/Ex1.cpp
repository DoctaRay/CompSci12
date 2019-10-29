#include<vector>
#include<iostream>
#include<string>
#include<utility>

using namespace std;

void calc(int x, int y, int count = 0) {
    x -= y;
    count++;
    if (x < y) {
        cout << count << "R" << x  << endl;
        return;
    }
    calc(x, y, count);
}

int main() {
    int x;
    int y;
    int count;

    cout << "Enter dividend: ";
    cin >> x;
    cout << "Enter divisor: ";
    cin >> y;

    calc(x, y);
}