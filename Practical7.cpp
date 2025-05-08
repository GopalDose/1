#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> src, vector<vector<int>> dest){
    int cnt = 0;
    for(int i = 0; i < src.size(); i++){
        for(int j = 0; j < src[0].size(); j++){
            if(src[i][j] != dest[i][j]) cnt++;
        }
    }
    return cnt;
}

struct Node{
    vector<vector<int>> state;
    int g;
    int h;
    int f;
    int x, y;

    Node(vector<vector<int>> state, int g, int h, int x, int y){
        this->state = state;
        this->g = g;
        this->h = h;
        this->f = g+h;
        this->x = x;
        this->y = y;
    }
};

bool operator>(const Node& a, const Node& b) {
    return a.f > b.f;
}

void printState(vector<vector<int>>& state, int f) {
    for (int i = 0; i < state.size(); i++) {
        for (int j = 0; j < state[0].size(); j++) {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
    cout << "f(n) = " << f << endl;
}

void astar(vector<vector<int>> src, vector<vector<int>> dest){
    int n = src.size();
    int m = src[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> visited;

    int startX, startY;
    for(int i = 0; i < src.size(); i++){
        for(int j = 0; j < src[0].size(); j++){
            if(src[i][j] == 0){
                startX = i;
                startY = j;
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int h = check(src, dest);
    Node start(src, 0, h, startX, startY);
    pq.push(start);
    visited.insert(src);

    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();

        if(curr.state == dest){
            cout<<"Goal Reached !!!!"<<endl;
            printState(curr.state, curr.f);
            return;
        }

        for(int i = 0; i < 4; i++){
            int newx = curr.x + dx[i];
            int newy = curr.y + dy[i];

            if(newx >= 0 && newy >=0 && newx < n && newy < m){
                vector<vector<int>> nextState = curr.state;
                swap(nextState[curr.x][curr.y], nextState[newx][newy]);

                if(visited.find(nextState) == visited.end()){
                    int newh = check(nextState, dest);
                    Node newNode(nextState, curr.g+1, newh, newx, newy);

                    pq.push(newNode);
                    visited.insert(nextState);
                    cout<<"Current State after move: (F(n) = "<< newNode.f << ")"<<endl;
                    printState(nextState, newNode.f);
                }

            }
        }
    }
    cout << "No solution found!" << endl;
}

int main(){
    vector<vector<int>> dest= {
        {0, 2, 3},
        {1, 4, 5},
        {7, 8, 6}
    };

    vector<vector<int>> src= {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    astar(src, dest);
    return 0;

}