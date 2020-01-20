#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int get_position(char x)
{
    return tolower(x) - 'a' + 1;
}

char get_char(int x)
{
    return toupper('a' + x);
}

class Graph
{

public:
    vector<vector<int> > Edge;
    
    Graph(int V)
    {
        Edge.resize(V);
    }

    void graphSize()
    {
        printf("Size of graph: %d\n", Edge.size());
    }

    void addEdge(int s, int d)
    {
        Edge[s - 65].push_back(d - 65);
        printf("%c -> %c\n", s, d);
        //Edge[d].push_back(s);
    }

    //change to bool?
    bool bfs(int start, int end, int allPaths[])
    {
        //change them to 0-based ascii values
        start = start - 65;
        end = end - 65;

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


        while (!q.empty())
        {
            start = q.front();
            cout << "start int:" << start << endl;
            cout << "start:" << char(start + 65) << endl;
            //count++;
            q.pop_front();
            for (int i : Edge[start])
            {
                cout << "i: " << char(i + 65) << endl;
                if (!visited[i])
                {
                    visited[i] = true;
                    allPaths[i] = start;
                    cout << "allPaths[i]: " << allPaths[i] << endl;
                    //cout << "i: " << char(i) << endl;
                    q.push_back(i);
                    if (i == end)
                    {
                        //cout << "count: " << count << endl;
                        cout << "bloop" << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void printShortestDistance(char start, char end)
    {
        // predecessor[i] array stores predecessor of
        // i and distance array stores distance of i
        // from s
        int pred[Edge.size()];

        if (bfs(start, end, pred) == false)
        {
            cout << "Given source and destination"
                 << " are not connected";
            return;
        }

        // vector path stores the shortest path
        vector<int> path;
        int crawl = end - 65;
        path.push_back(crawl);
        while (pred[crawl] != -1)
        {
            cout << "crawl " << crawl << endl;
            cout << "pred[crawl] " << pred[crawl] << endl;
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }

        // printing path from source to destination
        cout << "\nPath is:\n";
        for (int i = path.size() - 1; i >= 0; i--)
            cout << char(path[i] + 65) << " ";

        
    }
};

void checkBombPaths(Graph origGraph)
{
    for (int i = 0; i < origGraph.Edge.size(); i++)
    {

    }
}

int main(int argc, char const *argv[])
{
    ifstream file;
    file.open("data.txt");

    int numRoads = 0;
    int numNodes = int('A');
    string line;
    vector<vector<char> > roadsVec;

    while (getline(file, line))
    {
        if (line != "**")
        {
            numRoads++;
            vector<char> tempVec;
            tempVec.push_back(line[0]);
            tempVec.push_back(line[1]);
            roadsVec.push_back(tempVec);
            //cout << line[0] << "->" << line[1] << endl;

            if (int(line[0]) > numNodes)
                numNodes = int(line[0]);
            if (int(line[1]) > numNodes)
                numNodes = int(line[1]);
        }
    }

    cout << "numNodes:" << numNodes - 65 + 1 << endl;

    Graph g(numNodes + 1 - 65);

    for (auto x : roadsVec)
    {
        //cout << x[0] << " " << x[1] << endl;
        g.addEdge(x[0], x[1]);
        g.addEdge(x[1], x[0]);
    }

    char start = 'A', end = 'B';
    g.printShortestDistance(start, end);
}
