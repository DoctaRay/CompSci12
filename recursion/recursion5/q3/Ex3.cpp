#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//do it opposite way
int fib(int num, int prev = 1, int prev2 = 1) {
    int tmp = prev + prev2;
    prev = prev2;
    num--;
    if (num == 1) {
        return prev;
    }
    return fib(num, prev2, tmp);
}

int main() {
    int num;

    cout << "Enter term of fibonacci sequence: " << endl;
    cin >> num;

    cout << "Term " << num <<  " is " << fib(num) << " in Fibonacci sequence";
}
