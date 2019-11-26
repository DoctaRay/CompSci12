#include <vector>
#include <fstream>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;

struct Edge {
	int src;
	int dest;
};

void BFS(int vertex, int endVertex, int nodeNum, list<int> adjList) {
	bool visited [nodeNum];
	for (auto x : visited)
		x = false;

	list<int> queue;

	visited[vertex] = true;
	queue.push_back(vertex);

	list<int>::iterator itr;

	while (!queue.empty()) {
		vertex = queue.front();
		cout << vertex << " ";
		queue.pop_front();

		for (itr = adjList[vertex].begin(); itr != adjList[vertex].end(); ++itr) {
			//if not visited
			if (!visited[itr]) {
				visited[itr] = true;
				queue.push_back(itr);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data.txt");
	int numNodes, numPaths, shahirNode, dateNode

	cin >> numNodes >> numPaths >> shahirNode >> dateNode;

	list<int> adjList;

	for (int i = 0; i < numPaths; i++) {
		int x, y;
		cin >> x >> y;
		adjList[x].push_back[y];
	}

	cout << "BFS occuring" << endl;
	BFS(shahirNode, dateNode, numNodes, adjList);

	return 0;
}