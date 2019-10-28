#include <fstream>
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
    {'A', 'D', 'L', 'E', 'S' },
    {'U', 'O', 'C', 'S', 'E'},
    {'P', 'O', 'D', 'A', 'I'}
};

char board2[5][5] =
{
    {'G', 'S', 'T', 'G', 'T'},
    {'A', 'A', 'R', 'L', 'S'},
    {'A', 'D', 'L', 'E', 'S' },
    {'U', 'O', 'C', 'S', 'E'},
    {'P', 'O', 'D', 'A', 'I'}
};

vector<string> dictionary;


void print(char board[5][5]) {
    for (int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void quickSort(vector<string> &a, int start, int end)
{

        int i = start;
        int j = end;

        if (j - i >= 1)
        {
            string pivot = a[i];
            while (j > i)
            {
                while (a[i].compare(pivot) <= 0 && i <= end && j > i){
                    i++;
                }
                while (a[j].compare(pivot) >= 0 && j >= start && j >= i){
                    j--;
                }
                if (j > i)
                    swap(a[i], a[j]);
                }

            swap(a[start], a[j]);
            quickSort(a, start, j - 1);
            quickSort(a, j + 1, end);
        }
}

int binarySearch(vector<string> vec, string x, int n) {
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;

    int res;
    if (x == (vec[m])) {
        cout << "t1 " << vec[m] << endl;
        res = 0;
    }

    // Check if x is present at mid
        if (res == 0) {
            cout << "t2" << vec[m] << endl;
            return m;
        }

        // If x greater, ignore left half
        if (x > (vec[m])) {
            cout << "t3" << vec[m] << endl;
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else {
            cout << "t4" << vec[m] << endl;
            r = m - 1;
        }
  }

  return -1;
}

string strupper(string& str) {
    string temp = "";
    for (auto x: str) {
        temp += toupper(x);
    }
    return temp;
}

string strlower(string& str) {
    string temp = "";
    for (auto x: str) {
        temp += tolower(x);
    }
    return temp;
}

bool check(string word, int x, int y, int index=0, string cur = "") {
    usleep(50000);

    //char board2[5][5];
    //copy(begin(board), end(board), begin(board2));

    cout << endl;
    print(board2);

    if (x < 0 || y < 0 || x>4||y>4) {
        //cout << "Cur is " << cur << endl;
        //cout << "Word is" << word << " has been found! " << endl;
        //cout << "t1" << endl;
        return false;
    }

    if(word.compare(cur) == 0) {
        //board[x][y] = word[index - 1];
        cout << "Cur is " << cur << endl;
        cout << word << " has been found! " << endl;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                board2[i][j] = board[i][j];
            }
        }
        return true;
    }

    if (board2[x][y] != word[index]) {
        //cout << "t2" << endl;
        return false;
    }

    index++;
    cur.push_back(board2[x][y]);
    cout << cur;
    board2[x][y] = 'x';

    // can't go back to letter eg. pop can't do p, o then back to first p

    //north
    if (check(word, x, y-1, index, cur)) {
        return true;
    }
    //northeast
    if (check(word, x+1, y-1, index, cur)) {
        return true;
    }
    //east
    if (check(word, x+1, y, index, cur)) {
        return true;
    }
    //southeast
    if (check(word, x+1, y+1, index, cur)) {
        return true;
    }
    //south
    if (check(word, x, y+1, index, cur)) {
        return true;
    }
    //southwest
    if (check(word, x-1, y+1, index, cur)) {
        return true;
    }
    //west
    if (check(word, x-1, y, index, cur)) {
        return true;
    }
    //northwest
    if (check(word, x-1, y-1, index, cur)) {
        return true;
    }

    return false;
}

bool guess() {
    string word;
    cout << "Guess a word" << endl;
    cin >> word;

    if (binarySearch(dictionary, word, dictionary.size()) != -1) {
        vector<int> x, y;
        bool found;

        word = strupper(word);
        cout << word << endl;

        for (int i=0; i<5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j]==word[0]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        for (int i = 0; i < x.size(); i++) {
            //cout << "yeet" << endl;
            cout << endl << x[i] << " " << y[i] << endl;
        }

        for (int i = 0; i < x.size(); i++) {
            if (check(word, x[i], y[i]) == true) {
                found = true;
                cout << "You found a word" << endl;
                guess();
            }
        }

        if (!found) {
            cout << "Word's not there" << endl;
            guess();
        }
    }
    else {
        cout << "Word is not in dictionary. Guess again." << endl;
        guess();
    }
}

int main() {
    char c;
    int r;
    ifstream infile;
    ofstream outfile;
    string str;

    infile.open("dictionary.txt");

    while(getline(infile, str)) {
        //cout << "yeet " << str << endl;
        dictionary.push_back(str);
    }

    infile.close();

    quickSort(dictionary, 0, dictionary.size() - 1);

    outfile.open("sorted.txt");
    for (auto x: dictionary) {
        outfile << x << endl;
    }
    outfile.close();

    // for (auto x: dictionary) {
    //     cout << x << endl;
    // }

    // srand (time(NULL));    // initialize the random number generator
    // for (int i=0; i<6; i++) {
    //     for (int j = 0; j < 6; j++) {
    //         r = rand() % 26;   // generate a random number
    //         c = 'a' + r;            // Convert to a character from a-z
    //         board[i][j] = toupper(c);
    //         board2[i][j] = toupper(c);
    //     }
    // }

    print(board);
    guess();
    print(board);




}