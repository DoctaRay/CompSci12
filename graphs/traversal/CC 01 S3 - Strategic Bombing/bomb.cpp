// C++ program to print all paths from a source to destination. 
#include<iostream> 
#include <list> 
#include <fstream>
#include <vector>
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
    list<int> *adj; // Pointer to an array containing adjacency lists 

    // A recursive function used by printAllPaths() 
    void printAllPathsUtil(int , int , bool [], int [], int &); 

public: 
    Graph(int V); // Constructor 
    void addEdge(char u, char v); 
    void printAllPaths(char s, char d); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(char u, char v) 
{ 
    cout << "lulu" << endl;
    adj[get_position(u)].push_back(get_position(v)); // Add v to u’s list. 
} 

// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(char s, char d) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 


    // Create an array to store paths 
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 

    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

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
    cout << "lulu" << endl;

    // If current vertex is same as destination, then print 
    // current path[] 
    if (u == d) 
    { 
        for (int i = 0; i<path_index; i++) 
            cout << get_char(path[i]) << " "; 
        cout << endl; 
        
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, d, visited, path, path_index); 
    } 

    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
} 

// Driver program 
int main() 
{ 
    // Create a graph given in the above diagram 
    ifstream file;
    file.open("data.txt");
    string str;
    vector<vector<char> > temp;

    int max = get_position('A');
    //cout << get_position('A') << endl;
    while(getline(file, str)) {
        if (str != "**") {
            vector<char> temp2 = {str[0], str[1]};
            cout << str << endl;
            temp.push_back(temp2);
            if (get_position(str[0]) > max)
                max = get_position(str[0]);
            if (get_position(str[1]) > max)
                max = get_position(str[1]);
        }
    }


    //cout << max << endl;
    Graph g(max);

    for (auto x: temp) {
        cout << x[0] << " " << x[1] << endl;
        g.addEdge(x[0], x[1]); 
    }

    char s = 'A', d = 'B'; 
    cout << "Following are all different paths from " << s 
        << " to " << d << endl; 
    g.printAllPaths(s, d); 

    return 0; 
} 

