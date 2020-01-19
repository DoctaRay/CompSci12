#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// void handler(int sig) {
//   void *array[10];
//   size_t size;

//   // get void*'shahirIndex for all entries on the stack
//   size = backtrace(array, 10);

//   // print out all the frames to stderr
//   fprintf(stderr, "Error: signal %dateIndex:\n", sig);
//   backtrace_symbols_fd(array, size, STDERR_FILENO);
//   exit(1);
// }

class Graph
{
    vector<vector<int> > Edge;
    //vector unsigned char is faster than vector bool -> https://stackoverflow.com/questions/32821113/why-vectorint-is-faster-than-vectorbool-in-the-following-case
public:
    Graph(int V)
    {
        Edge.resize(V);
    }

    void add_edge(int v, int w)
    {
        Edge[v].push_back(w);
    }

    string BFS(int shahirIndex, int dateIndex)
    {
        vector<unsigned char> visited;
        visited.resize(Edge.size());
        for(auto i : visited) i = false;
        list<int> q;
        //int count = 0;
        visited[shahirIndex] = true;
        q.push_back(shahirIndex);
        if (shahirIndex == dateIndex)
        {
            return "GO SHAHIR!";
        }
        while (!q.empty())
        {
            shahirIndex = q.front();
            //cout<<shahirIndex<<" ";
            //cout << "yeet" << endl;
            //count++;
            q.pop_front();
            for (auto i : Edge[shahirIndex])
            {
                if (!visited[i])
                {
                    //cout << "vistied" << endl;
                    visited[i] = true;
                    //cout << "i: " << i << endl;
					if (i == dateIndex) {
					    //cout << "count: " << count << endl;
						//cout << "bloop" << endl;
                        return "GO SHAHIR!";
					} 
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
    ifstream file;
    file.open("data.txt");
    int numNode, numPaths, shahirIndex, dateIndex;

    file >> numNode >> numPaths >> shahirIndex >> dateIndex;
    //cout << numNode << " " << numPaths << " " << shahirIndex << " " << dateIndex << endl << endl;

    Graph g(numNode + 1);
    int x, y;
    for (int i = 1; i <= numPaths; i++)
    {
        //cout << "not me " << endl;
        file >> x >> y;
        //printf("%d <-> %d\n", x, y);
        //cout << i << endl;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }
    //cout << endl;

    cout << g.BFS(shahirIndex, dateIndex) << endl;
    //cout << "lil" << endl;=
    // int v;
    // cout<<"Enter vertex from where to perform BFS"<<endl;
    // cin>>v;
    // g.BFS(2);
    // cout<< (char)true;
}
