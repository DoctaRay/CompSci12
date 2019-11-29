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
    //vector unsigned char is faster than vector bool -> https://stackoverflow.com/questions/32821113/why-vectorint-is-faster-than-vectorbool-in-the-following-case
    vector<unsigned char> visited; 
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
            //cout<<s<<" ";
            //cout << "yeet" << endl;
            q.pop_front();
            for(auto i : Edge[s])
            {
                if(!visited[i])
                {
                    //cout << "vistied" << endl;
                    visited[i] = true;
                    q.push_back(i);
                }
                //cout << "i: " << i << endl;
            }
        }
        //cout << "ended" << endl;
        return "NO SHAHIR!";

    }

};

int main()
{
    //signal(SIGSEGV, handler);   // install our handler
    
}
