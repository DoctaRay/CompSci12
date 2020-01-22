#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Graph 
{
	vector<vector<int> > Edge;

public: 
	Graph(int V)
	{
		Edge.resize(V);
	}


	void addEdge(int s, int d)
	{
		Edge[s].push_back(d);
		Edge[d].push_back(s);
		//printf("%d -> %d\n", s, d);
		//Edge[d].push_back(s);
	}

	bool bfs(int start, int end, int allPaths[]) {
		vector<unsigned char> visited;
		visited.resize(Edge.size());

		//cout << "start: " << start << endl;
		//cout << "end: " << end << endl;

		if (start == end) {
			//cout << "start and end are same" << endl;
			return true;
		}

		for (int i = 0; i < visited.size(); i++) {
			allPaths[i] = -1;
			visited[i] = false;
		}

		list<int> q;
		visited[start] = true;
		q.push_back(start);
		//int count = 0;
		// if (start == end) {
		// 			////cout << "count: " << count << endl;
		// 	return count;
		// }

		while (!q.empty()) 
		{
			start = q.front();
			////cout << "start:" << start << endl;
			//count++;
			q.pop_front();
			for (auto i : Edge[start]) 
			{
				if (!visited[i])
				{
					visited[i] = true;
					allPaths[i] = start;
					//cout << "i: " << i << endl;
					q.push_back(i);
					if (i == end) {
					////cout << "count: " << count << endl;
						//cout << "bloop" << endl;
						//return count;
						return true;
					} 
				} 
			}
		}
		return false;
	}

	int shortestDistance(int start, int end)
    {
        // predecessor[i] array stores predecessor of
        // i and distance array stores distance of i
        // from s
		vector<int> path;

        int pred[Edge.size()];

		if (start == end) { 
			//cout << "bleh" << endl;
			return 0;
		}

        if (bfs(start, end, pred) == false)
        {
            return -1;
        }

        // vector path stores the shortest path
        int crawl = end;
        path.push_back(crawl);
        while (pred[crawl] != -1)
        {
            // //cout << "crawl " << crawl << endl;
            // //cout << "pred[crawl] " << pred[crawl] << endl;
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }

        //printing path from source to destination
        //cout << "\nPath is:\n";
        for (int i = path.size() - 1; i >= 0; i--)
            //cout << path[i] << " ";
		//cout << endl;
        // //cout << endl;
        return path.size() - 1;
    }

};



int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data2.txt");

	int numHouses, numRoads, numErrands, houseC;
	
	cin >> numHouses >> numRoads >> numErrands >> houseC;
	
	int roads [numRoads][2];
	int errands [numErrands][2];

	Graph g(numHouses + 1);
	////cout << "numHouses: " << numHouses << endl;

	int x, y;

	//g.graphSize();
	
	for (int i = 1; i <= numRoads; ++i) {
		cin >> x >> y;
		////cout << x << " " << y << endl;
		//cout << i << endl;
		g.addEdge(x,y);
	}

	//cout << "numErrands: " << numErrands << endl;
	int c, d;
	for (int i = 0; i < numErrands; ++i) {
		//		//cout << "yikes" << endl;
		cin >> c >> d;
		//cout << "c: " << c << endl;
		//cout << "d: " << d << endl;
		int dest1 = g.shortestDistance(c, houseC);
		//cout << "dest1: " << dest1<<endl;
		//cout << "------------------" << endl;
		int dest2 = g.shortestDistance(houseC, d);
		//cout << "dest2:  " << dest2<<endl;
		//cout << "------------------" << endl;
		int total = dest1 + dest2;

		if (dest1 < 0 || dest2 < 0) {
			cout << "This is a scam!" << endl;
		} else {
			cout << total << endl;
		}
		//cout << "****************" << endl;
	}  
	////cout << "lulu" << endl;

	// for (int i = 0; i < numRoads; ++i) {
	// 	//cout << i << endl;
	// }

	// for (int i = 0; i < numErrands; ++i) {
	// 	int dest1 = g.bfs(houseC, errands[i][0]);
	// 	int dest2 = g.bfs(houseC, errands[i][1]);

	// 	if (dest1 < 0 || dest2 < 0) {
	// 		//cout << "This is a scam!" << endl;
	// 	} else {
	// 		//cout << dest1 + dest2 << endl;
	// 	}
	// }  


	
	return 0;
}