#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        v = v;
        adj.resize(v);
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void DFSRec(int start, vector<bool> &visited, int level)
    {
        visited[start] = true;
        cout << "Visited " << start << " at level " << level << endl;

        for (auto i : adj[start])
        {
            if (!visited[i])
            {
                DFSRec(i, visited, level + 1);
            }
        }
    }

    void DFS(int s)
    {
        vector<bool> visited(v, false);
        cout << "<------ DFS ------->" << endl;
        DFSRec(s, visited, 0);
    }

    void BFSRec(vector<bool> &visited, queue<pair<int, int>> &q)
    {
        if (q.empty())
            return;
        auto n = q.front();
        q.pop();

        int node = n.first, level = n.second;
        cout << "Visited " << node << " at level " << level << endl;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                q.push({i, level + 1});
                visited[i] = true;
            }
        }
        BFSRec(visited, q);
    }

    void BFS(int s)
    {
        vector<bool> visited(v, false);
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, 0});
        cout << "<------ BFS ------->" << endl;
        BFSRec(visited, q);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.DFS(0);
    g.BFS(0);
}