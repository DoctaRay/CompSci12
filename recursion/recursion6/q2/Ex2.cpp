#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool guess(int i, int count) {
    int attempt;
    cout << "Guess the number: ";
    cin >> attempt;
    if (attempt!= i) {
            if (guess(i, ++count)) {
                cout << "You've solved the puzzle! The number was: " << i << endl;
                return false;
            };
    } else if (attempt == i){
        cout << "You've solved the puzzle! The number was: " << i << endl;
        return false;
    }
}

int main() {
   srand (time(NULL));
   int i = (rand()%20) + 2;
   int count = 0;
   if (guess(i, ++count)) {

   };
}