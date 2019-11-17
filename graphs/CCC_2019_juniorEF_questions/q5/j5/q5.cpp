#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

struct Replacement {
    int ruleNum;
    int index;
};

struct Node {
    string prev; 
    //int next;
    Replacement how; // how it was done
    string curr;
};

void findAllOccurances(std::string data, std::string toSearch [2], int ruleNum, int prevIndex, vector<Node> &nodeLevel)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch[0]);

 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
        Node t;
        t.how.ruleNum = ruleNum;
        t.how.index = pos;
        string temp = data;
		// Add position to the vector
		//vec.push_back(pos);
        temp.replace(pos, toSearch[0].length(), toSearch[1]);
        cout << temp << endl;
        cout << "wut " << endl;
        t.curr = temp;
        t.prev = data;
        nodeLevel.push_back(t);
 
		// Get the next occurrence from the current position
		pos =data.find(toSearch[0], pos + toSearch[0].size());
	}
}

int main(int argc, const char** argv) {
    //int vertices, edges;
    //unordered_map< string, list< pair<string, int> > > adjacencyList(vertices + 1);

    ifstream file;
    file.open("data2.txt");
    int index;
    string init,fin;

    //mapping to the value it becomes
    string one [2], two [2], three[2];
    int steps;

    string rules [3][2];

    file >> rules[0][0] >> rules[0][1];
    file >> rules[1][0] >> rules[1][1];
    file >> rules[2][0] >> rules[2][1];


    file >> steps >> init >> fin;

    printf("%s %s \n%s %s \n%s %s \n%d %s %s\n\n", one[0].c_str(), one[1].c_str(), two[0].c_str(), two[1].c_str(), three[0].c_str(), three[1].c_str(), steps, init.c_str(), fin.c_str());

    vector<vector<Node> > list;
    for (int i = 0; i < steps + 1; i++) {
        vector<Node> t;
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

    Node t;
    t.how.index = 0;
    t.how.ruleNum = 0;
    t.curr = init;
    t.prev = "";
    list[0].push_back(t);

    for (int j = 0; j + 1< list.size(); j++) {
        vector<Node> x = list[j];
        cout << x.size() << endl;
        for (int i = 0; i < x.size(); i++) {
            cout << "iter " << j << " " << i << endl;
            cout << x[i].curr << endl;
            cout << "One" << endl;
            findAllOccurances(x[i].curr, rules[0], 1, i, list[j+1]);
            cout << "Two" << endl;
            findAllOccurances(x[i].curr, rules[1], 2, i, list[j+1]);
            cout << "Three" << endl;
            findAllOccurances(x[i].curr, rules[2], 3, i, list[j+1]);
            cout << "------------------------" << endl;
        }
        cout << list[j+1].size() << endl;
        cout << "*******************" << endl;
    }

    string textToFind = fin;
    vector<Node> result;
    for (int i = steps; i >= 0; i--)
    {
        //find end result element
        for (int j = 0; j < list[i].size(); j++) 
        {
            if (list[i][j].curr.compare(textToFind) ==0) 
            {
                result.push_back(list[i][j]);
                cout << list[i][j].how.ruleNum << " " << list[i][j].how.index << " " << textToFind << endl;
                textToFind = list[i][j].prev;
                cout << textToFind << endl;
                break;
            }
        }
    }

    for (int i = result.size()-2; i >= 0; i--)
    {
        cout << result[i].how.ruleNum << " " << result[i].how.index+1 << " " << result[i].curr << endl;
    }

    return 0;
}