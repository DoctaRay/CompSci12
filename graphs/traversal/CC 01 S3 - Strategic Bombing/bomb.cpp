// C++ program to print all paths from a source to destination. 
#include <iostream> 
#include <list> 
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std; 

int get_position(char x) {
    return tolower(x) - 'a' + 1;
}

char get_char(int x) {
    return toupper('a' + x);
}

// A directed graph using adjacency list representation 
class Graph 
{ 
    int V; // No. of vertices in graph 
    list<int> *adj; // Pointer to an array containing adjacency lists i.e vector of set size arrays

    // A recursive function used by printAllPaths() 
    void printAllPathsUtil(int , int , bool [], int [], int &); 

public: 
    Graph(int V); // Constructor 
    void addEdge(char u, char v); 
    void printAllPaths(char s, char d); 
    vector<vector<char> > result;
    char start;
    char end;
}; 

Graph::Graph(int V) 
{   
    //number of nodes
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(char u, char v) 
{ 
    //cout << u << " " << v << endl;
    //cout << get_position(u) << " " << get_position(v) << endl << "--" << endl;
    adj[get_position(u)].push_back(get_position(v)); // Add v to u’s list. 

    //twice because it's undirected
    adj[get_position(v)].push_back(get_position(u));
} 

// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(char s, char d) 
{ 
    start = s;
    end = d;
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 


    // Create an array to store paths. Int because arrays use numbers and using maps would be too complex
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 

    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    //cout << adj->size() << endl;

    // Call the recursive helper function to print all paths 
    printAllPathsUtil(get_position(s), get_position(d), visited, path, path_index); 
} 

// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int u, int d, bool visited[], 
                            int path[], int &path_index) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
    //cout << "lulu" << endl;
    //cout << "kek" << endl;
    
    // If current vertex is same as destination, then print 
    // current path[] 
    if (u == d) 
    { 
        //cout << "kek" << endl;
        std::vector<char> temp;
        for (int i = 0; i<path_index; i++)  {
            if (get_char(path[i] - 1) == start || get_char(path[i] - 1) == end){
                //cout << "get char " << get_char(path[i] - 1) << endl;
                continue;
            }
            temp.push_back(get_char(path[i] - 1));
            //cout << get_char(path[i] - 1) << " ";
        }
        //cout << "y" << endl; 
        result.push_back(temp);
        //cout << endl;
        
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            //cout << "u: " << u << endl;
            //cout << get_char(*i - 1) << endl;
            if (!visited[*i]) {
                //cout << "visited i: " << get_char(*i - 1) << endl;
                printAllPathsUtil(*i, d, visited, path, path_index); 
            }
        }
    } 

    // Remove current vertex from path[] and mark it as unvisited 
    path_index--;
    //cout << "u: " << get_char(u) << endl; 
    visited[u] = false; 
} 

// Driver program 
int main() 
{ 
    // Create a graph given in the above diagram 
    ifstream file;
    file.open("data2.txt");
    string str;
    vector<vector<char> > temp;
    vector<string> orig;

    //numNodes is number conversion of the last letter in dataset
    int numNodes = get_position('A');
    
    int numEdges = 0;
    //cout << get_position('A') << endl;
    while(getline(file, str)) {
        if (str != "**") {
            numEdges++;
            vector<char> temp2;
            temp2.push_back(str[0]);
            temp2.push_back(str[1]);

            orig.push_back(str);
            
            temp.push_back(temp2);
            if (get_position(str[0]) > numNodes)
                numNodes = get_position(str[0]);
            if (get_position(str[1]) > numNodes)
                numNodes = get_position(str[1]); 
        }
    }


    //cout << max << endl;
    
    Graph g(numEdges+1);
    //char orig [count][2]; 
    for (auto x: temp) {
        //cout << x[0] << " " << x[1] << endl;
        g.addEdge(x[0], x[1]); 
        g.addEdge(x[1], x[0]); 
    }

    char s = 'A', d = 'B'; 
    //cout << "Following are all different paths from " << s << " to " << d << endl; 
    g.printAllPaths(s, d); 


    // cout << endl << "result vector" << endl;
    // for (auto x: g.result) {
    //     for (auto y: x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    /**
     * Finding all the nodes between two nodes 
    **/
    vector<int> v(g.result[0].size() + g.result[1].size()); 
    vector<int>::iterator it, st; 

    it = set_intersection(g.result[0].begin(), 
                          g.result[0].end(), 
                          g.result[1].begin(), 
                          g.result[1].end(), 
                          v.begin()); 
  
    vector<char> pattern;
    //cout << "\nCommon elements:\n"; 
    for (st = v.begin(); st != it; ++st) {
        pattern.push_back(char(*st));
        //cout << char(*st) << ", "; 
    }
    //cout << '\n'; 

    vector<vector<char> > copy; 
    for (auto x: g.result) {
        sort(x.begin(), x.end());
        copy.push_back(x);
    }

    numEdges = 0;
    for (auto x: copy) {
        if (!includes(x.begin(), x.end(), pattern.begin(), pattern.end())) {
            for (auto y: x)
                //cout << y << " ";
            //cout << endl;
            goto aa;
            break;
        } else {
            numEdges = pattern.size() - 1;
        }
    }


    if (numEdges != 0) {
        for (int i = 0; i +1< pattern.size(); i++) {
            string s = "";
            s+= pattern[i+1];
            s+= pattern[i];
            //cout << "s: " << s << endl;
            if (find(orig.begin(), orig.end(), s) != orig.end()) {
                //cout << "lulu" << endl;
                cout << pattern[i+1] << pattern[i] << endl;
            } else 
                cout << pattern[i] << pattern[i+1] << endl;
        }
        cout << "There are " << numEdges << " disconnecting roads." << endl;
        return 0;
    }

    aa: {
        cout << "There are 0 disconnecting roads." << endl;
    }

    return 0; 
} 

