#include <ostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

char board[5][5] =
{
    {'G', 'S', 'T', 'G', 'T'},
    {'A', 'A', 'R', 'L', 'S'},
    {'P', 'D', 'L', 'E', 'S' },
    {'U', 'O', 'C', 'S', 'E'},
    {'P', 'O', 'T', 'R', 'I'}
};

void print(char board[5][5]) {
    for (int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool check(string word, int x, int y, int index=1, string cur = "") {
    usleep(50000);
    print(board);

    if(board[x][y] == putchar(toupper(word[word.size() - 1]))) {
        cout << word << " has been found! " << endl;
        return true;
    }

    if (board[x][y] != putchar(toupper(word[index]))) return false;

    index++;
    cur += board[x][y];

    //north
    if (check(word, x, y-1, index, cur)) {
        return true;
    }
    //northeast
    if (check(word, x+1, y-1, index)) {
        return true;
    }
    //east
    if (check(word, x+1, y, index)) {
        return true;
    }
    //southeast
    if (check(word, x+1, y+1, index)) {
        return true;
    }
    //south
    if (check(word, x, y+1, index)) {
        return true;
    }
    //southwest
    if (check(word, x-1, y+1, index)) {
        return true;
    }
    //west
    if (check(word, x-1, y, index)) {
        return true;
    }
    //northwest
    if (check(word, x-1, y-1, index)) {
        return true;
    }

}

void guess() {
    string word;
    cout << "Guess a word" << endl;
    cin >> word;
    vector<int> x, y;

    for (int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j]==putchar(toupper(word[0]))) {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    for (int i = 0; i < x.size(); i++) {
        cout << "yeet" << endl;
        cout << x[i] << " " << y[i] << endl;
    }

    for (int i = 0; i < x.size(); i++) {
        if (check(word, x[i], y[i]) == true) {
            cout << "You found a word" << endl;
            guess();
        } else {
            cout << "Word's not there" << endl;
            guess();
        }
    }
}

int main() {
    char c;
    int r;

    // srand (time(NULL));    // initialize the random number generator
    // for (int i=0; i<6; i++) {
    //     for (int j = 0; j < 6; j++) {
    //         r = rand() % 26;   // generate a random number
    //         c = 'a' + r;            // Convert to a character from a-z
    //         board[i][j] = c;
    //     }
    // }

    guess();
    print(board);




}