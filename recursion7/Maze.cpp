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

vector<vector<char> > maze;

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

bool findpath(int x, int y) {
    if (x < 0 || y < 0) return false;
    if (maze[x][y] == 'x') {
        return true;
    }
    if (maze[x][y] == '%') return false;

    maze[x][y] = '+';

    //north
    if (findpath(x, y-1) == true) return true;

    //south
    if (findpath(x , y+1) == true) return true;

    //east
    if (findpath(x+1, y)==true) return true;

    //west
    if(findpath(x-1, y) == true) return true;

    maze[x][y] = '.';
    findpath(x, y);

    return false;
//   int possPathsNum = 0;
//   map<char, bool> possPaths = {
//       {'N', false},
//       {'E', false},
//       {'W', false},
//       {'S', false}
//   };
//     cout << "t1" << endl;
//     // east
//     if (mazesol[current[0]][current[1]+1] == '.' && current[1]+1 > 0) {
//         cout << "t2" << endl;
//         possPathsNum++;
//         possPaths['E'] = true;
//     }
//     //south
//     if (mazesol[current[0]+1][current[1]] == '.' && current[0]+1 > 0) {
//       cout << "t3" << endl;
//       possPathsNum++;
//       possPaths['S'] = true;
//     }
//     //north
//     if (mazesol[current[0] - 1][current[1]] == '.' && current[0]-1 > 0)  {
//       cout << "t4" << endl;
//       possPathsNum++;
//       possPaths['N'] = true;
//     }
//     //west
//     if (mazesol[current[0]][current[1] - 1] == '.' && current[1] - 1 > 0) {
//       cout << "t5" << endl;
//       possPathsNum++;
//       possPaths['W'] = true;
//     }

//     cout << possPathsNum << endl;

//     if (possPathsNum > 1) {
//       if (possPaths['N'] == true && triedPaths['N'] == false) {
//         current[0]--;
//         mazesol[current[0]][current[1]] = '+';
//         triedPaths['N'] = true;
//         findpath(mazesol, current, exit, triedPaths);
//       }
//       else if (possPaths['E'] == true && triedPaths['E'] == false) {
//         current[1]++;
//         mazesol[current[0]][current[1]] = '+';
//         triedPaths['E'] = true;
//         findpath(mazesol, current, exit, triedPaths);
//       }
//       else if (possPaths['W'] == true && triedPaths['W'] == false) {
//         current[1]--;
//         mazesol[current[0]][current[1]] = '+';
//         triedPaths['W'] = true;
//         findpath(mazesol, current, exit, triedPaths);
//     }
//       else if (possPaths['S'] == true && triedPaths['S'] == false) {
//         current[0]++;
//         mazesol[current[0]][current[1]] = '+';
//         triedPaths['S'] = true;
//         print(mazesol);
//         findpath(mazesol, current, exit, triedPaths);
//       }
//     }

//     if (possPaths['N'] == true) {
//         cout << "t6" << endl;
//         current[0]--;
//         if (mazesol[current[0]][current[1]] == 'x') {
//             print(mazesol);
//             return;
//         }
//         mazesol[current[0]][current[1]] = '+';
//         findpath(mazesol, current, exit, triedPaths);
//     }
//     else if (possPaths['E'] == true) {
//         cout << "t7" << endl;
//         current[1]++;
//         if (mazesol[current[0]][current[1]] == 'x') {
//             print(mazesol);
//             return;
//         }
//         mazesol[current[0]][current[1]] = '+';
//         findpath(mazesol, current, exit, triedPaths);
//     }
//     else if (possPaths['W'] == true) {
//         cout << "t8" << endl;
//         current[1]--;
//         if (mazesol[current[0]][current[1]] == 'x') {
//             print(mazesol);
//             return;
//         }
//         mazesol[current[0]][current[1]] = '+';
//         findpath(mazesol, current, exit, triedPaths);
//     }
//     else if (possPaths['S'] == true) {
//         cout << "t9" << endl;
//         current[0]++;
//         if (mazesol[current[0]][current[1]] == 'x') {
//             print(mazesol);
//             return;
//         }
//         mazesol[current[0]][current[1]] = '+';
//         findpath(mazesol, current, exit, triedPaths);
//     }
}

int main() {
    ifstream infile;
    ofstream outfile;
    string str;
    vector<int> enter (2), exit (2);
    int sx,sy;
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
                sx = x;
                enter[1] = y;
                sy = y;
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
    cout << endl;

    map<char, bool> temp = {
      {'N', false},
      {'E', false},
      {'W', false},
      {'S', false}
    };

    if(findpath(sx, sy)) {
        print(maze);
    };
    //call function with current as enter coords. tried paths are all false
}