//#include "stdc++.h"
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
public:
    map<char,vector<char> > adjList;
    void addEdge(char node1, char node2, bool isBidirectional);
    void bfs(char src);
};

void Graph::addEdge(char node1, char node2, bool isBidirectional = true)
{
    adjList[node1].push_back(node2);
    if(isBidirectional)
        adjList[node2].push_back(node1);

}
void Graph::bfs(char src)
{
    queue<char> q;
    map<char, bool> visited;
    for (auto x: adjList) {
        visited[x.first] = false;
    }
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        char node = q.front();
        cout << node << ", ";
        q.pop();
        for(char neighbor: adjList[node])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void Graph::bfsHelper(char u, char d, map<char, bool> visited, )

int main()
{
    Graph g;
    ifstream file;
    file.open("data.txt");
    string str;
    while (getline(file, str)) {
        if (str != "**") {
            g.addEdge(str[0], str[1]);
            cout << str + "\n";
        }
    }
    g.bfs('A');
    // g.addEdge('A', 'B');
    // g.addEdge('A', 'C');
    // g.addEdge('A', 'D');
    // g.addEdge('B', 'E');
    // g.addEdge('B', 'F');
    // g.addEdge('D', 'K');
    // g.addEdge('F', 'I');
    // g.addEdge('F', 'J');
    //g.bfs('A');

    return 0;
}