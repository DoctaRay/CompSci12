#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void findpath(vector<vector<char> > mazesol, vector<int> enter, vector<int> exit, vector<int> current) {
    /*
    Finding walls
    */
    //east
    if (mazesol[current[0] + 1][current[1]] == '%') {
        //recurse
    }
    //south
    if (mazesol[current[0]][current[1] + 1] == '%') {

    }
    //north
    if (mazesol[current[0] - 1][current[1]] == '%') {

    }
    //west
    if (mazesol[current[0]][current[1] - 1] == '%') {

    }

    /*
    Finding possible spots
    */
    if (mazesol[current[0] + 1][current[1]] == '%') {
        //recurse
    }
    //south
    if (mazesol[current[0]][current[1] + 1] == '%') {

    }
    //north
    if (mazesol[current[0] - 1][current[1]] == '%') {

    }
    //west
    if (mazesol[current[0]][current[1] - 1] == '%') {

    }
}

int main() {
    ifstream infile;
    ofstream outfile;
    vector<vector<char> > maze;
    string str;
    vector<int> enter (2), exit (2);
    string waste;

    infile.open("data1.txt");

    getline(infile, waste);

    while(getline(infile, str)) {
        vector<char> temp;
        for (auto x: str) {
            temp.push_back(x);
        }
        maze.push_back(temp);
    }

    for (int x = 0; x < maze.size(); x++) {
        for (int y = 0; y < maze[x].size(); y++) {
            if (maze[x][y] == 'e') {
                enter[0] = x;
                enter[1] = y;
            } if (maze[x][y] == 'x') {
                exit[0] = x;
                exit[1] = y;
            }
            cout << maze[x][y];
        }
        cout << endl;
    }
    for (auto x: enter) cout << x;
    cout << endl;
    for (auto x: exit) cout << x;

    //call function with current as enter coords
}