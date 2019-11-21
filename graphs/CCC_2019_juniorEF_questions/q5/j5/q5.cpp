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

void quickSort(vector<Node> &a, int start, int end)
{
        
        int i = start;
        int j = end;


        if (j - i >= 1)
        {
            cout << "yeet" << endl;
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

    cout << "string comparing " << x << endl;
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int res = x.compare(vec[m].curr);
    cout << "string being compared: " << vec[m].curr << endl;

    // if (x == (vec[m])) {
    //     cout << "t1 " << vec[m] << endl;
    //     res = 0;
    // }

    // Check if x is present at mid
        if (res == 0) {
            //cout << "t2" << vec[m] << endl;
            //wordsf.push_back(vec[m]);
            return m;
        }

        // If x greater, ignore left half
        if (res > 0) {
            //cout << "t3" << vec[m] << endl;
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else {
            //cout << "t4" << vec[m] << endl;
            r = m - 1;
            //cout << vec[m].compare(x) << endl;
            /*cout << l << endl;
            cout << r << endl;
            cout << m << endl;
            cout << res << endl;
            cout << x << endl;
            cout << x.compare(vec[m]) << endl;*/
            //if(x.compare(vec[m]) == 0) return m;
        }

  }

  return -1;
}


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
        //cout << "wut " << endl;
        t.curr = temp;
        t.prev = data;
        cout << "node level size" << nodeLevel.size() << endl;
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

    printf("%s %s \n%s %s \n%s %s \n%d %s %s\n\n", one[0].c_str(), one[1].c_str(), two[0].c_str(), two[1].c_str(), three[0].c_str(), three[1].c_str(), steps, init.c_str(), fin.c_str());

    cout << "Rev" << endl;
    for (auto x: rulesRev) {
        cout << x[0] << " " << x[1] << endl;

    }

    vector<vector<Node> > list;
    vector<vector<Node> > list2;

    if (steps % 2 != 0) {
        steps--;
    }

    for (int i = 0; i < steps / 2 + 1; i++) {
        vector<Node> t;
        list.push_back(t);
    }
    cout << "Size" << list.size() << endl;
    

    for (int i = 0; i < steps / 2 + 1; i++) {
        vector<Node> t;
        list2.push_back(t);
    }

    //vector<size_t> vec; 
    // while (true) {
    //     index = init.find(one[0]);
    //     if (index != string::npos) {
    //         init.replace(index, 1, one[1]);
    //         break;
    //     }
    // }

    // cout << init << endl;

    //creating node for initial string search
    Node t;
    t.how.index = 0;
    t.how.ruleNum = 0;
    t.curr = init;
    t.prev = "";
    list[0].push_back(t);
    cout << list[0][0].curr << endl;

    //creating node for final string search
    t.curr = fin;
    list2[0].push_back(t);
    cout << list2[0][0].curr << endl;

    


    //creating 1st half variations / nodes
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

    //creating 2nd half variation
    cout << "2nd" << endl << endl <<endl;
    for (int j = 0; j< list2.size() && j+1 < list2.size(); j++) {
        vector<Node> x = list2[j];
        cout << x.size() << endl;
        for (int i = 0; i < x.size(); i++) {
            cout << "iter " << j << " " << i << endl;
            cout << "varying " << x[i].curr << endl;
            cout << "vec size" << list2.size();
            cout << "One" << endl;
            findAllOccurances(x[i].curr, rulesRev[0], 1, i, list2[j+1]);
            cout << "Two" << endl;
            findAllOccurances(x[i].curr, rulesRev[1], 2, i, list2[j+1]);
            cout << "Three" << endl;
            findAllOccurances(x[i].curr, rulesRev[2], 3, i, list2[j+1]);
            cout << "------------------------" << endl;
        }
        cout << list2[j+1].size() << endl;
        cout << "*******************" << endl;
    }


    //finding path
    string textToFind = init;
    vector<Node> result;

    cout << "items in list" << endl;
    int count = 0;
    for (auto x: list) {
        count++;
        cout << count << endl;
        for (auto y: x) {
            cout << y.curr << " ";
        }
        cout << endl;
    }

    cout << list[1].size() << endl;
    for (int i = list.size(); i >= 0; i--)
    {
           cout << "booP1" << endl;
        //find end result element
        // for (int j = 0; j < list[i].size(); j++) 
        // {
        //     // if (list[i][j].curr.compare(textToFind) ==0) 
        //     // {
        //     //     result.push_back(list[i][j]);
        //     //     cout << list[i][j].how.ruleNum << " " << list[i][j].how.index << " " << textToFind << endl;
        //     //     textToFind = list[i][j].prev;
        //     //     cout << textToFind << endl;
        //     //     break;
        //     // }
            
        // }
        //quicksort should be size - 1
        quickSort(list[i], 0, list[i].size() - 1);
        //x is index of textToFind in list2
        int x = binarySearch(list[i], textToFind, list[i].size());
        //cout << "braP1" << endl;
        cout << "x: " << x << endl;
        if (x != - 1){
            cout << "added"<< endl;
            result.push_back(list[i][x]);
            //cout << "mrap" << endl;
            textToFind = list[i][x].prev;
        } 
    }
    cout << "booP2" << endl << endl;
    cout << list2.size();
    vector<Node> result2;
    textToFind = fin;

    for (int i = list2.size() - 1; i >= 0; i--)
    {
        //find end result element
        // for (int j = 0; j < list[i].size(); j++) 
        // {
        //     // if (list[i][j].curr.compare(textToFind) ==0) 
        //     // {
        //     //     result.push_back(list[i][j]);
        //     //     cout << list[i][j].how.ruleNum << " " << list[i][j].how.index << " " << textToFind << endl;
        //     //     textToFind = list[i][j].prev;
        //     //     cout << textToFind << endl;
        //     //     break;
        //     // }
            
        // }
        //quicksort should be size - 1
        quickSort(list2[i], 0, list2[i].size() - 1);
        int x = binarySearch(list2[i], textToFind, list2[i].size());
        if (x != - 1){
            cout << "added"<< endl;
            result2.push_back(list2[i][x]);
            textToFind = list2[i][x].prev;
        }
    }

    cout << "result1 " << endl;
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i].how.ruleNum << " " << result[i].how.index+1 << " " << result[i].curr << endl;
    }

    cout << "result2 " << endl;
    for (int i = result2.size() - 1; i >= 0; i--)
    {
        cout << result2[i].how.ruleNum << " " << result2[i].how.index+1 << " " << result2[i].curr << endl;
    }

    return 0;
}