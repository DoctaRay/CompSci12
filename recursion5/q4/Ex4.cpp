#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int separate(int num, int count=0, int sum = 0) {
    int temp;
    //cout << "power is" << (int)pow(10, count);
    temp = num / (int)pow(10, count) % 10;
    count++;
    //cout << "count is " << count << endl;
    //cout << temp << endl;

    sum += temp;
    return separate(num, count);
}

int main() {
    int num;
    cout << "Enter number to separate: " << endl;
    cin >> num;

    cout << "The sum is " << separate(num) << endl;
}