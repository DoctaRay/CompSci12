#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

struct Replacement {
    int index;
    int charNum;
};

struct Node {
    int prev; //indices of previous coordinate string
    int next;
    Replacement how; // how it was done
    string curr;
};

void findAllOccurances(std::string data, std::string toSearch [2], vector<string> &nodeLevel)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch[0]);

 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
        string temp = data;
		// Add position to the vector
		//vec.push_back(pos);
        temp.replace(pos, toSearch[0].length(), toSearch[1]);
        nodeLevel.push_back(temp);
        cout << temp << endl;
 
		// Get the next occurrence from the current position
		pos =data.find(toSearch[0], pos + toSearch[0].size());
	}
}

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

    printf("%s %s \n%s %s \n%s %s \n%d %s %s\n\n", one[0].c_str(), one[1].c_str(), two[0].c_str(), two[1].c_str(), three[0].c_str(), three[1].c_str(), steps, init.c_str(), fin.c_str());

    vector<vector<string> > list;
    for (int i = 0; i < steps + 1; i++) {
        vector<string> t;
        list.push_back(t);
    }

    vector<size_t> vec; 
    // while (true) {
    //     index = init.find(one[0]);
    //     if (index != string::npos) {
    //         init.replace(index, 1, one[1]);
    //         break;
    //     }
    // }

    // cout << init << endl;

    list[0].push_back(init);

    for (int j = 0; j + 1< list.size(); j++) {
        vector<string> x = list[j];
        cout << x.size() << endl;
        for (int i = 0; i < x.size(); i++) {
            cout << "iter " << j << " " << i << endl;
            cout << x[i] << endl;
            cout << "One" << endl;
            findAllOccurances(x[i], one, list[j+1]);
            cout << "Two" << endl;
            findAllOccurances(x[i], two, list[j+1]);
            cout << "Three" << endl;
            findAllOccurances(x[i], three, list[j+1]);
            cout << "------------------------" << endl;
        }
        cout << list[j+1].size() << endl;
        cout << "*******************" << endl;
    }

    return 0;
}
