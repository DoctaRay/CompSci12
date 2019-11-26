#include <vector>
#include <fstream>
#include <list>
#include <iterator>
#include <iostream>
#include <queue>

using namespace std;

vector<bool> v; 
vector<vector<int> > g; 
  
void edge(int a, int b) 
{ 
    g[a].push_back(b); 
  
    // for undirected graph add this line 
    // g[b].pb(a); 
} 
  
void bfs(int u) 
{ 
    queue<int> q; 
  
    q.push(u); 
    v[u] = true; 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
            } 
        } 
    } 
}

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data.txt");
	int numNodes, numPaths, shahirNode, dateNode;

	file >> numPaths >> numNodes >> shahirNode >> dateNode;

	list<int> adjList;

	for (int i = 0; i < numPaths; i++) {
		int x, y;
		file >> x >> y;
		edge(x, y);
	}

    cout << g.size() << endl;

	cout << "BFS occuring" << endl;
	for (int i = 0; i < numNodes; i++) {
		if (!v[i])
			bfs(i);
	}

	return 0;
}