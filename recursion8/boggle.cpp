#include <ostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void print(char board[5][5]) {
    for (int i=0; i<6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool check(string word) {

}

void guess() {
    string word;
    cout << "Guess a word" << endl;
    cin >> word;
    if (check(word) == true) {
        cout << "You found a word" << endl;
        guess();
    }
}

int main() {
    char c;
    int r;
    char board[5][5] =
    {
        {'C', 'S', 'T', 'E', 'T'},
        {'A', 'I', 'R', 'L', 'S'},
        {'P', 'D', 'A', 'E', 'S' },
        {'U', 'E', 'C', 'S', 'E'},
        {'R', 'O', 'T', 'R', 'I'}
    };

    // srand (time(NULL));    // initialize the random number generator
    // for (int i=0; i<6; i++) {
    //     for (int j = 0; j < 6; j++) {
    //         r = rand() % 26;   // generate a random number
    //         c = 'a' + r;            // Convert to a character from a-z
    //         board[i][j] = c;
    //     }
    // }

    print(board);




}