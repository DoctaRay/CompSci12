#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    string prev;
    string next;
    string curr;
};

int main(int argc, const char** argv) {
    //int vertices, edges;
    //unordered_map< string, list< pair<string, int> > > adjacencyList(vertices + 1);

    ifstream file;
    file.open("data1.txt");
    int index;
    string init,fin;

    //mapping to the value it becomes
    string one [2], two [2], three[2];
    int steps;

    file >> one[0] >> one[1];
    file >> two[0] >> two[1];
    file >> three[0] >> three[1];

    file >> steps >> init >> fin;

    printf("%s %s %s %s %s %s %d %s %s", one[0].c_str(), one[1].c_str(), two[0].c_str(), two[1].c_str(), three[0].c_str(), three[1].c_str(), steps, init.c_str(), fin.c_str());

    vector<vector<Node> > list;
    for (int i = 0; i < steps; i++) {
        vector<Node> t;
        list.push_back(t);
    }

    while (true) {
        index = init.find(one[0]);
        if (index != string::npos) {
            init.replace(one[1], index, one[1].length());
        }
    }

    return 0;
}
