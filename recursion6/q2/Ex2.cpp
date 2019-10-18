#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool guess(int i, int count) {
    int guess;
    cout << "Guess the number";
    cin >> guess;
    if (guess != i) {

    }
}

int main() {
   int i = (rand()%20) + 1;
   if (guess(i, 1)) {
       cout << "You've solved the puzzle!";
   };
}