#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Graph 
{
	int V;
	list<int> *adj;

public: 
	Graph(int V);
	void addEdge(int s, int d);

};

void Graph::addEdge(int s, int d) 
{

}

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("data.txt");

	int numHouses, numRoads, numErrands, houseC;
	int roads [numRoads][2];
	int errands [numErrands][2];
	
	file >> numHouses >> numRoads >> numErrands >> houseC;
	
	for (int i = 0; i < numRoads; ++i) {
		file >> roads[i][0] >> roads[i][1];
	}

	for (int i = 0; i < numErrands; ++i) {
		file >> errands[i][0] >> errands[i][1];
	}  


	
	return 0;
}