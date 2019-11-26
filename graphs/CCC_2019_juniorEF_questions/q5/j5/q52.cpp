//#include <unordered_map>
#include <iostream>
#include <string>
//#include <list>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <time.h>

using namespace std;

struct Node {
    Node *prevNode; 
    //Node *nextNode;
    //int next;

    int ruleNum;
    int index;
    string curr;

    // string returnCurr() {
    // 	return curr;
    // }
};

void quickSort(vector<Node> &a, int start, int end)
{
        
        int i = start;
        int j = end;


        if (j - i >= 1)
        {
            string pivot = a[i].curr;
            while (j > i)
            {
                while (a[i].curr.compare(pivot) <= 0 && i <= end && j > i){
                    i++;
                }
                while (a[j].curr.compare(pivot) >= 0 && j >= start && j >= i){
                    j--;
                }
                if (j > i)
                    swap(a[i], a[j]);
                }

            swap(a[start], a[j]);
            quickSort(a, start, j - 1);
            quickSort(a, j + 1, end);
        }
}

int binarySearch(vector<Node>& vec, string x, int n) {

    //cout << "string comparing " << x << endl;
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int res = x.compare(vec[m].curr);
    //cout << "string being compared: " << vec[m].curr << " with index " << m << endl;

    // if (x == (vec[m])) {
    //     //cout << "t1 " << vec[m] << endl;
    //     res = 0;
    // }

    // Check if x is present at mid
        if (res == 0) {
            ////cout << "t2" << vec[m] << endl;
            //wordsf.push_back(vec[m]);
            return m;
        }

        // If x greater, ignore left half
        if (res > 0) {
            ////cout << "t3" << vec[m] << endl;
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else {
            ////cout << "t4" << vec[m] << endl;
            r = m - 1;
            ////cout << vec[m].compare(x) << endl;
            /*//cout << l << endl;
            //cout << r << endl;
            //cout << m << endl;
            //cout << res << endl;
            //cout << x << endl;
            //cout << x.compare(vec[m]) << endl;*/
            //if(x.compare(vec[m]) == 0) return m;
        }

  }

  return -1;
}


void findAllOccurances(std::string data, std::string toSearch [2], int ruleNum, Node *prevNode, vector<Node>& nodeLevel)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch[0]);
	//cout << pos << endl;

	// if (pos == std::string::npos) {
	// 	//cout <<"true"<<endl;
	// }
	Node prev = *prevNode;

	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		//cout << pos << endl;
        Node t;
        t.ruleNum = ruleNum;
        t.index = pos;
        string temp = data;
		// Add position to the vector
		//vec.push_back(pos);
        temp.replace(pos, toSearch[0].length(), toSearch[1]);
        
        ////cout << "wut " << endl;
        t.curr = temp;

        //cout << temp << endl;

        t.prevNode = prevNode;
        
        // Node k = *prevNode;
        // string str = k.curr;
        // //cout << str << endl;
        //cout << "node level size" << nodeLevel.size() << endl;
        nodeLevel.push_back(t);
        ////cout << t.prevNode << endl;
		// Get the next occurrence from the current position
		pos =data.find(toSearch[0], pos + toSearch[0].size());

	}
}

// void findAllOccurancesBack(std::string data, std::string toSearch [2], int ruleNum, Node *prevNode, vector<Node>& nodeLevel)
// {
// 	// Get the first occurrence
// 	size_t pos = data.find(toSearch[0]);
// 	//cout << pos << endl;

// 	// if (pos == std::string::npos) {
// 	// 	//cout <<"true"<<endl;
// 	// }

// 	// Repeat till end is reached
// 	while( pos != std::string::npos)
// 	{
// 		//cout << pos << endl;
//         Node t;
//         t.ruleNum = ruleNum;
//         t.index = pos;
//         string temp = data;
// 		// Add position to the vector
// 		//vec.push_back(pos);
//         temp.replace(pos, toSearch[0].length(), toSearch[1]);
        
//         ////cout << "wut " << endl;
//         t.curr = temp;

//         //cout << temp << endl;

//         t.prevNode = prevNode
        
//         // Node k = *prevNode;
//         // string str = k.curr;
//         // //cout << str << endl;
//         //cout << "node level size" << nodeLevel.size() << endl;
//         nodeLevel.push_back(t);
//         ////cout << t.prevNode << endl;
// 		// Get the next occurrence from the current position
// 		pos =data.find(toSearch[0], pos + toSearch[0].size());

// 	}
// }

int checkAllOccurances(Node list1Node, vector<Node> list2LastRow, vector<Node>& list1LastRow, std::string toSearch [2], int ruleNum)
{
	// Get the first occurrence
	size_t pos = list1Node.curr.find(toSearch[0]);

	// Repeat till end is reached
	while( pos != std::string::npos)
	{
        // Node t;
        //  t.ruleNum = ruleNum;
        //  t.index = pos;
        string temp = list1Node.curr;

		// Add position to the vector
		//vec.push_back(pos);
        temp.replace(pos, toSearch[0].length(), toSearch[1]);
        //cout << temp << endl;
        ////cout << "wut " << endl;
        int x = binarySearch(list2LastRow, temp, list2LastRow.size());
        //cout << "x: " << x << endl;
        if (x != -1) {
        	Node t;
         	t.ruleNum = ruleNum;
         	t.index = pos;
        	t.curr = temp;
        	t.prevNode = &list1Node;
        	list1LastRow.push_back(t);
        	//cout << list1LastRow.size() << endl;
        	//cout << "found" << endl;
        	return x;
        }
        // t.curr = temp;
        // t.prevNode = prevNode;
        // //cout << "node level size" << nodeLevel.size() << endl;
        // nodeLevel.push_back(t);
		// Get the next occurrence from the current position
		pos =list1Node.curr.find(toSearch[0], pos + toSearch[0].size());

	}
	return -1;
}

int main(int argc, const char** argv) {
    //int vertices, edges;
    //unordered_map< string, list< pair<string, int> > > adjacencyList(vertices + 1);
    clock_t start = clock();
    ifstream file;
    file.open("data10.txt");
    int index;
    string init,fin;

    //mapping to the value it becomes
    string one [2], two [2], three[2];
    int steps;

    string rules [3][2];
    string rulesRev [3][2];

    file >> rules[0][0] >> rules[0][1];
    file >> rules[1][0] >> rules[1][1];
    file >> rules[2][0] >> rules[2][1];

    rulesRev[0][0] = rules[0][1];
    rulesRev[0][1] = rules[0][0];
    rulesRev[1][0] = rules[1][1];
    rulesRev[1][1] = rules[1][0];
    rulesRev[2][0] = rules[2][1];
    rulesRev[2][1] = rules[2][0];



    file >> steps >> init >> fin;


    //printf("%s %s \n%s %s \n%s %s \n%d %s %s\n\n", one[0].c_str(), one[1].c_str(), two[0].c_str(), two[1].c_str(), three[0].c_str(), three[1].c_str(), steps, init.c_str(), fin.c_str());

    //cout << "Rev" << endl;
    // for (auto x: rulesRev) {
    //     //cout << x[0] << " " << x[1] << endl;

    // }
    //cout << endl << endl;

    vector<vector<Node> > list;
    vector<vector<Node> > list2;

    if (steps == 3) {
    	vector<Node> temp;
    	//1 space must be left for initial node
    	for (int i = 0; i < steps; i++) {
    		list.push_back(temp);
    	}

    	//list 2 is bigger one 
    	////cout << "lulu" << endl;
    	for (int i = 0; i < 1; i++) {
    		list2.push_back(temp);
    	}
    }
    else if (steps % 2 != 0) {
    	vector<Node> temp;
    	//1 space must be left for initial node
    	for (int i = 0; i < (steps - 1) / 2 + 1; i++) {
    		list.push_back(temp);
    	}

    	
    	////cout << "lulu" << endl;
    	for (int i = 0; i < (steps-1) / 2; i++) {
    		list2.push_back(temp);
    	}
    } else {
    	vector<Node> temp;
    	//1 space must be left for initial node
    	for (int i = 0; i < steps / 2; i++) {
    		list.push_back(temp);
    	}

    	for (int i = 0; i < steps / 2 + 1; i++) {
    		list2.push_back(temp);
    	}
    }

    //creating initial nodes for both lists
    Node t;
    t.curr = init;
    t.ruleNum = 0;
    t.index = -1;
    t.prevNode = nullptr;
    list[0].push_back(t);

    //node starting backwards
    Node s;
    s.curr = fin;
    s.ruleNum = 0;
    s.index = -1;
    //s.nextNode = nullptr;
    list2[0].push_back(s);

    //creating variations 
    //cout << "creating list 1" << endl;
    for (int i = 0; i + 1< list.size(); i++) {
    	vector<Node> x = list[i];
    	//cout << "i: " << i << endl;
    	for (int j = 0; j< x.size(); j++) {

    		////cout << "boop" << endl;
    		//cout << "x[j].curr: " << x[j].curr << endl;
    		//cout << "first" << endl;
    		findAllOccurances(x[j].curr, rules[0], 1, &list[i][j], list[i+1]);
    		////cout << "boop2" << endl;
    		//cout << "second" << endl;
    		findAllOccurances(x[j].curr, rules[1], 2, &list[i][j], list[i+1]);
    		//cout << "third" << endl;
    		findAllOccurances(x[j].curr, rules[2], 3, &list[i][j], list[i+1]);
    	}
    }


    // //cout << "list 1 size: " << list.size() << endl << endl;
    // //cout << list[0][0].curr << endl;
    // //cout << list[1][0].curr << endl;

    //cout << "creating list 2" << endl;
    for (int i = 0; i + 1< list2.size(); i++) {
    	vector<Node> x = list2[i];
    	//cout << "i: " << i << endl;

    	for (int j = 0; j< x.size(); j++) {
    		////cout << "boop" << endl;
    		//cout << "x[j].curr: " << x[j].curr << endl;
    		//cout << "first" << endl;
    		findAllOccurances(x[j].curr, rulesRev[0], 1, &list2[i][j], list2[i+1]);
    		////cout << "boop2" << endl;
    		//cout << "second" << endl;
    		findAllOccurances(x[j].curr, rulesRev[1], 2, &list2[i][j], list2[i+1]);
    		//cout << "third" << endl;
    		findAllOccurances(x[j].curr, rulesRev[2], 3, &list2[i][j], list2[i+1]);
    	}
    }

    //cout << "---------------" << endl;

    //cout << "items in list1 " << endl;
    // int count = 0;
    // for (auto x: list) {

    //     //cout << count << endl;
    //     for (auto y: x) {
    //         //cout << y.curr << " ";
    //     }
    //     count++;
    //     //cout << endl;
    // }
    // count = 0;
    //cout << "++++++++++++++++++++" << endl;
    //cout << list.size() << endl;

    //reading lists
    // for (int x = 1; x < list.size(); x++) {
    // 	vector<Node> temp = list[x];
    // 	//quickSort(list[x], 0, list[x].size() - 1);
    //     //cout << count << endl;
    //     for (int y = 0; y < temp.size() && temp[y].prevNode != NULL; y++) {
    //     	//cout << "temp size: " << temp.size() << endl;
    //     	//string l = &y.prevNode -> curr;
    //     	////cout << temp[y].prevNode << endl;
    //     	Node prev = *(temp[y].prevNode);
    //     	//Node actual = **prev;
    //     	//Node actual = **prev;
    //     	string str = prev.curr;

    //         //cout << temp[y].curr << " derives from " <<  str << endl;
    //         ////cout << y.curr << " derives from " << y.prevNode -> returnCurr() << endl;

    //     }
    //     count++;
    //     //cout << endl;
    // }
    // //cout << "---------------" << endl;
    // count = 0;
    // for (auto x: list2) {

    //     //cout << count << endl;
    //     for (auto y: x) {
    //         //cout << y.curr << " ";
    //     }
    //     count++;
    //     //cout << endl;
    // }

    //cout << "++++++++++++" << endl;
    //cout << "items in list2 " << endl;
    // count = 0;
    // for (int x = 1; x < list2.size(); x++) {
    // 	vector<Node> temp = list2[x];
    // 	//quickSort(list2[x], 0, list2[x].size() - 1);
    //     //cout << count << endl;
    //     for (int y = 0; y < temp.size() && temp[y].prevNode != NULL; y++) {
    //     	//string l = &y.prevNode -> curr;
    //     	Node prev = *(temp[y].prevNode);
    //     	//Node actual = **prev;
    //     	//Node actual = **prev;
    //     	string str = prev.curr;
    //         //cout << temp[y].curr << " derives from " <<  str << endl;
    //         ////cout << y.curr << " derives from " << y.prevNode -> returnCurr() << endl;

    //     }
    //     count++;
    //     //cout << endl;
    // }

    //cout << "************" << endl;


	//quickSort(list[list.size() -1], 0, list[list.size() -1].size() - 1);
	quickSort(list2[list2.size() -1], 0, list2[list2.size() -1].size() - 1);
	//cout << "lulu" << endl;

	//extra space for node on connection  
	vector<Node> temp;
	list.push_back(temp);  

	//cout << endl << endl << "finding connection" << endl << endl;

    //finding connection in middle
    int indexAtList2LastRow;
    for (int i = 0; i < list[list.size()-2].size(); i++) {
    	vector<Node> x = list[list.size()-2];
    	//cout << "list[list.size()-2].size(): " << list[list.size()-2].size() << endl;
    	//cout << "i: " << i << endl;
    	//void checkAllOccurances(Node list1Node, vector<Node> list2LastRow, vector<Node> list1LastRow, std::string toSearch [2], int ruleNum)

    	//cout << endl << "first check " << x[i].curr << endl << endl;
    	indexAtList2LastRow = checkAllOccurances(x[i], list2[list2.size()-1], list[list.size()-1], rules[0], 1);
    	if (indexAtList2LastRow != - 1) {
    		//cout << "index is " << indexAtList2LastRow << endl;
    		break;
    	}

    	//cout << endl << "second check " << x[i].curr << endl << endl;
    	indexAtList2LastRow = checkAllOccurances(x[i], list2[list2.size()-1], list[list.size()-1], rules[1], 2);
    	if (indexAtList2LastRow != - 1) {
    		//cout << "index is " << indexAtList2LastRow << endl;
    		break;
    	}

    	//cout << endl << "third check " << x[i].curr << endl << endl;
    	indexAtList2LastRow = checkAllOccurances(x[i], list2[list2.size()-1], list[list.size()-1], rules[2], 3);
    	if (indexAtList2LastRow != - 1) {
    		//cout << "index is " << indexAtList2LastRow << endl;
    		break;
    	}

    	//cout << "======================" << endl;
    }

    vector<Node> halfOne;
    vector<Node> halfTwo;

    //cout << "list.size(): " << list.size() << endl;
    //cout << "list[list.size()-1].size(): " << list[list.size() -1].size() << endl;
    Node path = list[list.size() - 1][0];
    ////cout << "works" << endl;
    while (path.prevNode != nullptr) {
    	//cout << path.ruleNum << " " << path.index+1 << " " << path.curr << endl;
    	if (path.curr==init) {
    		//cout << "break" << endl;
    		break;
    	}
    	halfOne.push_back(path);
    	path = *(path.prevNode);
    	////cout << "lulu" << endl;
    }

    path = list2[list2.size()-1][indexAtList2LastRow];
    while (path.prevNode != nullptr) {
    	//cout << path.ruleNum << " " << path.index+1 << " " << path.curr << endl;
    	if (path.curr==fin) {
    		////cout << "break" << endl;
    		break;
    	}
    	halfTwo.push_back(path);
    	path = *(path.prevNode);
    }

    //cout << "final" << endl;
    for (int i = halfOne.size() - 1; i >= 0; i--)
    {
        cout << halfOne[i].ruleNum << " " << halfOne[i].index+1 << " " << halfOne[i].curr << endl;
    }

    for (int i = 0; i < halfTwo.size(); i++)
    {
    	Node temp = *(halfTwo[i].prevNode);
        cout << halfTwo[i].ruleNum << " " << halfTwo[i].index+1 << " " << temp.curr << endl;
    }

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);



}