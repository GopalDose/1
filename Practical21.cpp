#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class GraphColoring {
    int V;
    vector<vector<int>> adj;
    int minColorsUsed;
    vector<int> bestColoring;

public:
    GraphColoring(int V) {
        this->V = V;
        adj.resize(V);
        minColorsUsed = INT_MAX;
        bestColoring.resize(V, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isSafe(int node, int color, vector<int> &coloring) {
        for (int neighbor : adj[node]) {
            if (coloring[neighbor] == color) return false;
        }
        return true;
    }

    void backtrack(int node, vector<int> &coloring) {
        if (node == V) {
            set<int> usedColors(coloring.begin(), coloring.end());
            if (usedColors.size() < minColorsUsed) {
                minColorsUsed = usedColors.size();
                bestColoring = coloring;
            }
            return;
        }

        for (int c = 1; c <= V; ++c) {
            if (isSafe(node, c, coloring)) {
                coloring[node] = c;

                set<int> usedColors(coloring.begin(), coloring.begin() + node + 1);
                if (usedColors.size() <= minColorsUsed) {
                    backtrack(node + 1, coloring);
                }

                coloring[node] = 0; // Backtrack
            }
        }
    }

    void solve() {
        vector<int> coloring(V, 0);
        backtrack(0, coloring);

        cout << "Minimum colors used: " << minColorsUsed << endl;
        cout << "Coloring:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": Color " << bestColoring[i] << endl;
        }
    }
};

int main() {
    GraphColoring gc(4);
    gc.addEdge(0, 1);
    gc.addEdge(0, 2);
    gc.addEdge(1, 2);
    gc.addEdge(1, 3);
    gc.addEdge(2, 3);

    gc.solve();
    return 0;
}
