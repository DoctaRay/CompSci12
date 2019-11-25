#include <vector>
#include <cstdlib>
#include <fstream>
#include <set>
#include <unordered_map>

using namespace std;

struct Node {
	Node *motherNode;
	string name;
	int numSisters = 0;
	int numCousins = 0;
}

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("ecoo20.txt");

	unordered_map<string, vector<string> > list;

	int nodeNum;

	cin >> nodeNum;

	set<string, vector<string> > list;

	Node nodeArr [nodeNum];

	for (int i = 0; i < ansNum; i++) {
		Node mother;
		Node daughter;
		cin >> mother.name;
		cin >> daughter.name;
		daughter.motherNode = &mother;
		nodeArr[i] = daughter;
	}

	

}