#include <vector>
#include <cstdlib>
#include <fstream>
#include <unordered_set>
#include <iostream>

using namespace std;

struct Node {
	Node *motherNode;
	string name;
	int numSisters = 0;
	int numCousins = 0;
};

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("ecoo20.txt");

	unordered_set<string> uniqueNames;

	int nodeNum;

	cin >> nodeNum;

	//set<string, vector<string> > list;

	Node nodeArr [nodeNum];

	for (int i = 0; i < nodeNum; i++) {
		Node mother;
		Node daughter;
		cin >> mother.name;
		cin >> daughter.name;
		if (uniqueNames.find(mother.name) != uniqueNames.end()) {
			uniqueNames.insert(mother.name);
		} 
		else {
			daughter.motherNode = &mother;
			nodeArr[i] = daughter;
		}
	}

	

}