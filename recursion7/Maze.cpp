#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

void print(vector<vector<char> > maze) {
    for (int x = 0; x < maze.size(); x++) {
        for (int y = 0; y < maze[x].size(); y++) {
            cout << maze[x][y];
        }
        cout << endl;
    }
}

// bool check(vector<vector<char> > mazesol, vector<int> current, char look) {
//     int possPaths = 0;

//     if (mazesol[current[0] + 1][current[1]] == look) {
//         possPaths++;
//         //recurse
//     }
//     //south
//     if (mazesol[current[0]][current[1] + 1] == look) {
//         possPaths++;
//     }
//     //north
//     if (mazesol[current[0] - 1][current[1]] == look) {
//         possPaths++;
//     }
//     //west
//     if (mazesol[current[0]][current[1] - 1] == look) {
//         possPaths++;
//     }
// }

void findpath(vector<vector<char> > mazesol, vector<int> current, vector<int> exit, map<char, bool> triedPaths) {
  int possPathsNum = 0;
  map<char, bool> possPaths = {
      {'N', false},
      {'E', false},
      {'W', false},
      {'S', false}
  };

    // east
    if (mazesol[current[0]][current[1]+1] == '.') {
        possPathsNum++;
        possPaths['E'] = true;
    }
    //south
    if (mazesol[current[0]-1][current[1]] == '.') {
      possPathsNum++;
      possPaths['S'] = true;
    }
    //north
    if (mazesol[current[0] - 1][current[1]] == '.') {
      possPathsNum++;
      possPaths['N'] = true;
    }
    //west
    if (mazesol[current[0]][current[1] - 1] == '.') {
      possPathsNum++;
      possPaths['W'] = true;
    }

    if (possPathsNum > 1) {
      if (possPaths['N'] == true && triedPaths['N'] == false) {
        current[0]--;
        mazesol[current[0]][current[1]] = '+';
        triedPaths['N'] = true;
        findpath(mazesol, current, exit, triedPaths);
      }
      else if (possPaths['E'] == true && triedPaths['E'] == false) {
        current[1]++;
        mazesol[current[0]][current[1]] = '+';
        triedPaths['N'] = true;
        findpath(mazesol, current, exit, triedPaths);
      }
      else if (possPaths['W'] == true && triedPaths['W'] == false) {
        current[1]--;
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
    }
      else if (possPaths['S'] == true && triedPaths['S'] == false) {
        current[0]++;
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
      }
    }

    if (possPaths['N'] == true) {
        current[0]--;
        if (mazesol[current[0]][current[1]] == 'e') {
            print(mazesol);
            return;
        }
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
    }
    else if (possPaths['E'] == true) {
        current[1]++;
        if (mazesol[current[0]][current[1]] == 'e') {
            print(mazesol);
            return;
        }
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
    }
    else if (possPaths['W'] == true) {
        current[1]--;
        if (mazesol[current[0]][current[1]] == 'e') {
            print(mazesol);
            return;
        }
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
    }
    else if (possPaths['S'] == true) {
        current[0]++;
        if (mazesol[current[0]][current[1]] == 'e') {
            print(mazesol);
            return;
        }
        mazesol[current[0]][current[1]] = '+';
        findpath(mazesol, current, exit, triedPaths);
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
            }
            if (maze[x][y] == 'x') {
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

    findpath(maze, enter, exit, {
      {'N', false},
      {'E', false},
      {'W', false},
      {'S', false}
  });
    //call function with current as enter coords. tried paths are all false
}