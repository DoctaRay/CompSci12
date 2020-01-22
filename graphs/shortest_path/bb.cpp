bool bfs(int start, int end, int allPaths[], vector<vector<int> > Edge)
{


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
            //cout << "*****************" << endl;
            start = q.front();
            // cout << "start int:" << start << endl;
            // cout << "start:" << char(start + 65) << endl;
            //count++;
            q.pop_front();
            for (int i : Edge[start])
            {
                //cout << "i: " << char(i + 65) << endl;
                if (!visited[i])
                {
                    visited[i] = true;
                    allPaths[i] = start;
                    //cout << "allPaths[i]: " << allPaths[i] << endl;
                    //cout << "i: " << char(i) << endl;
                    q.push_back(i);
                    if (i == end)
                    {
                        //cout << "count: " << count << endl;
                        //cout << "bloop" << endl;
                        return true;
                    }
                }
            }
        }
        return false;
}