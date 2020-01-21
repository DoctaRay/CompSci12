#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

bool bfs(int start, int end, int allPaths[], unordered_map<int, vector<int> > Edge)
{
        //change them to their position in alphabet for vector index
        // start = start - 65;
        // end = end - 65;

        vector<unsigned char> visited;
        visited.resize(Edge.size());
        //cout << "start: " << char(start) << endl;
        //cout << "end: " << char(end) << endl;
        //cout << "edge size" << Edge.size() << endl;

        if (start == end)
            return true;
        
        for (int i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            allPaths[i] = -1;
        }
            

        list<int> q;
        visited[start] = true;
        q.push_back(start);
        //int count = 0;
        // if (start == end) {
        // 			//cout << "count: " << count << endl;
        // 	return count;
        // }

        /**
         * Some weird stuff is happening down here  
        **/
        while (!q.empty())
        {
            cout << "*****************" << endl;
            cout << "q size " << q.size() << endl; 
            cout << "q front " << q.front() << endl; 
            start = q.front();
            cout << "start:" << char(start) << endl;
            cout << "start int:" << start << endl;
            //count++;
            q.pop_front();
            cout << "Edge[start].size(): " << Edge[start].size() << endl;
            for (auto i : Edge[start]) 
            {
                cout << "i: " << i << endl;
                cout << "char i: " << char(i) << endl;
                if (!visited[i])
                {
                    visited[i] = true;
                    allPaths[i] = start;
                    cout << "allPaths[i]: " << allPaths[i] << endl;
                    //cout << "i: " << char(i) << endl;
                    q.push_back(i);
                    cout << "q i " << q.front() << endl;
                    if (i == end)
                    {
                        //cout << "count: " << count << endl;
                        cout << "bloop" << endl;
                        return true;
                    }
                    cout << "------" << endl;
                }
            }
        }
        return false;
}

class Graph
{
public:
    unordered_map<int, vector<int> > Edge;
    vector<int> path;

    void graphSize()
    {
        printf("Size of graph: %d\n", Edge.size());
    }

    void addEdge(string line)
    {
        Edge[int(line[0])].push_back(int(line[1]));
        Edge[int(line[1])].push_back(int(line[0]));
        printf("%c -> %c, size: %d\n", line[0], line[1], Edge[line[0]].size());
        //Edge[d].push_back(s);
    }

    void printShortestDistance(char start, char end)
    {
        // predecessor[i] array stores predecessor of
        // i and distance array stores distance of i
        // from s
        int pred[Edge.size()];

        if (bfs(start, end, pred, Edge) == false)
        {
            cout << "Given source and destination"
                 << " are not connected";
            return;
        }

        // vector path stores the shortest path
        int crawl = int(end);
        path.push_back(crawl);
        while (pred[crawl] != -1)
        {
            cout << "crawl " << crawl << endl;
            cout << "pred[crawl] " << pred[crawl] << endl;
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }

        // printing path from source to destination
        //cout << "path size " << path.size() << endl; 
        cout << "\nPath is:\n";
        for (int i = path.size() - 1; i >= 0; i--)
            cout << i << " " << char(path[i] + 65) << " ";

        cout << endl;
        for (int j = path.size() - 1; j >= 1; j--)
        {
            cout << char(path[j] + 65) << " -> " << char(path[j - 1] + 65) << endl;
        }

    }
};

int main(int argc, char const *argv[])
{
    ifstream file;
    file.open("data.txt");

    int numRoads = 0;
    int numNodes = int('A');
    string line;
    //chars are implemented in ints (ASCII)
    unordered_map<int, vector<int> > roadsVec;

    Graph g;

    while (getline(file, line))
    {
        if (line != "**")
        {
            numRoads++;
            vector<int> tempVec;
            roadsVec[int(line[0])].push_back(int(line[1]));
            roadsVec[int(line[1])].push_back(int(line[0])); 
            g.addEdge(line);

            //roadsVec.push_back(tempVec);

            //cout << line[0] << "->" << line[1] << endl;

            if (int(line[0]) > numNodes)
                numNodes = int(line[0]);
            if (int(line[1]) > numNodes)
                numNodes = int(line[1]);
        }
    }

    cout << "numNodes:" << numNodes - 65 + 1 << endl;

    // Graph g(numNodes + 1 - 65);

    // for (auto x : roadsVec)
    // {
    //     //cout << x[0] << " " << x[1] << endl;
    //     g.addEdge(x[0], x[1]);
    //     g.addEdge(x[1], x[0]);
    // }

    for (auto it = g.Edge.begin(); it != g.Edge.end(); it++)
    {
        cout << it->first << endl;
    }

    char start = 'A', end = 'B';
    g.printShortestDistance(start, end);
}
