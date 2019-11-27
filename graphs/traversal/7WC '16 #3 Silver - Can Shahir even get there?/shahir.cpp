//Modified version of http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
#include <fstream>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// void handler(int sig) {
//   void *array[10];
//   size_t size;

//   // get void*'s for all entries on the stack
//   size = backtrace(array, 10);

//   // print out all the frames to stderr
//   fprintf(stderr, "Error: signal %d:\n", sig);
//   backtrace_symbols_fd(array, size, STDERR_FILENO);
//   exit(1);
// }

class Graph
{
    vector< vector<int> > Edge;
    vector<unsigned char> visited; //We can use vector<bool>, but it's slow and broken :( , CPP's byte array http://stackoverflow.com/questions/10077771/what-is-the-correct-way-to-deal-with-medium-sized-byte-arrays-in-modern-c
public:
 
    Graph(int V)
    {
        Edge.resize(V);
        visited.resize(V);
    }

    void add_edge(int v,int w)
    {
        Edge[v].push_back(w);
    }

    string BFS(int s, int d)
    {
        for(auto i : visited) i = false;
        list<int> q;
        visited[s] = true;
        q.push_back(s);
        while (!q.empty())
        {
            s = q.front();
            if (s == d) {
                return "GO SHAHIR!";
            }
            cout<<s<<" ";
            cout << "yeet" << endl;
            q.pop_front();
            for(auto i : Edge[s])
            {
                if(!visited[i])
                {
                    cout << "vistied" << endl;
                    visited[i] = true;
                    q.push_back(i);
                }
                cout << "i: " << i << endl;
            }
        }
        cout << "ended" << endl;
        return "NO SHAHIR!";

    }

};

int main()
{
    //signal(SIGSEGV, handler);   // install our handler
    ifstream file;
    file.open("data.txt");
    int numNode, numPaths, shahirIndex, dateIndex;

    file >> numNode >> numPaths >> shahirIndex >> dateIndex;
    cout << numNode << numPaths << shahirIndex << dateIndex << endl << endl;

    Graph g(numNode);
    int x, y;
    for (int i = 1; i <= numPaths; i++) {
        cout << x << " " << y << endl;
        //cout << "not me " << endl;
        file >> x >> y;
        g.add_edge(x, y);
    }
    cout << endl;

    cout << g.BFS(shahirIndex, dateIndex) << endl;;
    //cout << "lil" << endl;
    // Graph g(6);
    // g.add_edge(0,1);
    // g.add_edge(0,2);
    // g.add_edge(1,2);
    // g.add_edge(2,0);
    // g.add_edge(2,3);
    // g.add_edge(3,3);
    // int v;
    // cout<<"Enter vertex from where to perform BFS"<<endl;
    // cin>>v;
    // g.BFS(2);
    // cout<< (char)true;
}
