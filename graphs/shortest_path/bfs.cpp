#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Graph 
{
	vector<vector<int> > Edge;
	vector<unsigned char> visited;

public: 
	Graph(int V)
	{
		Edge.resize(V);
		visited.resize(V);
	}

	void addEdge(int s, int d)
	{
		Edge[s].push_back(d);
		Edge[d].push_back(s);
	}

	int bfs(int start, int end) {
		for (auto i: visited) i = false;

		list<int> q;
		visited[start] = true;
		q.push_back(start);
		int count = 0;

		while (!q.empty()) 
		{
			start = q.front();
			count++;
			if (start == end) {
				//cout << "count: " << count << endl;
				return count;
			}
			q.pop_front();
			for (auto i : Edge[start]) 
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push_back(i);
				} 
			}
		}
		return -1;
	}

};

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data.txt");

	int numHouses, numRoads, numErrands, houseC;
	
	file >> numHouses >> numRoads >> numErrands >> houseC;
	
	int roads [numRoads][2];
	int errands [numErrands][2];

	Graph g(numRoads);
	//cout << "numHouses: " << numHouses << endl;

	int x, y;
	for (int i = 0; i < numRoads; ++i) {
		file >> x >> y;
		//cout << x << " " << y << endl;
		cout << i << endl;
		g.addEdge(x,y);
	}

	cout << "numErrands: " << numErrands << endl;
	int c, d;
	for (int i = 0; i < numErrands; ++i) {
		//		cout << "yikes" << endl;
		file >> c >> d;
		cout << "c: " << c << endl;
		cout << "d: " << d << endl;
		int dest1 = g.bfs(houseC, c);
		//cout << dest1<<endl;
		int dest2 = g.bfs(houseC, d);
		//cout << dest2<<endl;
		int total = dest1 + dest2;

		if (dest1 < 0 || dest2 < 0) {
			cout << "This is a scam!" << endl;
		} else {
			cout << total << endl;
		}
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