#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
	vector<vector<int>> Edge;

public:
	Graph(int V)
	{
		Edge.resize(V);
	}

	void graphSize()
	{
		printf("Size of graph: %d\n", Edge.size());
	}

	void addEdge(int s, int d)
	{
		Edge[s].push_back(d);
		Edge[d].push_back(s);
		//printf("%d -> %d\n", s, d);
		//Edge[d].push_back(s);
	}

	int bfs(int start, int end)
	{
		vector<bool> visited(Edge.size(), 0);

		vector<int> distance(Edge.size(), 0);

		queue<int> q;
		distance[start] = 0;

		q.push(start);
		visited[start] = true;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			for (int i = 0; i < Edge[x].size(); i++)
			{
				if (visited[Edge[x][i]])
					continue;

				// update distance for i
				distance[Edge[x][i]] = distance[x] + 1;
				q.push(Edge[x][i]);
				visited[Edge[x][i]] = 1;
			}
		}
		return distance[end];
	}
};

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data2.txt");

	int numHouses, numRoads, numErrands, houseC;

	file >> numHouses >> numRoads >> numErrands >> houseC;

	int roads[numRoads][2];
	int errands[numErrands][2];

	Graph g(numHouses + 1);
	//cout << "numHouses: " << numHouses << endl;

	int x, y;

	g.graphSize();

	for (int i = 1; i <= numRoads; ++i)
	{
		file >> x >> y;
		//cout << x << " " << y << endl;
		//cout << i << endl;
		g.addEdge(x, y);
	}

	//cout << "numErrands: " << numErrands << endl;
	int c, d;
	for (int i = 0; i < numErrands; ++i)
	{
		//		cout << "yikes" << endl;
		file >> c >> d;
		// cout << "c: " << c << endl;
		// cout << "d: " << d << endl;
		int dest1 = g.bfs(c, houseC);
		//  cout << "dest1: " << dest1<<endl;
		//  cout << "------------------" << endl;
		int dest2 = g.bfs(houseC, d);
		//  cout << "dest2:  " << dest2<<endl;
		//  cout << "------------------" << endl;
		int total = dest1 + dest2;

		if (dest1 <= 0 || dest2 <= 0)
		{
			cout << "This is a scam!" << endl;
		}
		else
		{
			cout << total << endl;
		}
		//cout << "****************" << endl;
	}
	//cout << "lulu" << endl;

	// for (int i = 0; i < numRoads; ++i) {
	// 	cout << i << endl;
	// }

	// for (int i = 0; i < numErrands; ++i) {
	// 	int dest1 = g.bfs(houseC, errands[i][0]);
	// 	int dest2 = g.bfs(houseC, errands[i][1]);

	// 	if (dest1 < 0 || dest2 < 0) {
	// 		cout << "This is a scam!" << endl;
	// 	} else {
	// 		cout << dest1 + dest2 << endl;
	// 	}
	// }

	return 0;
}