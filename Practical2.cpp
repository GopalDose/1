#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n; i++){
        int minVal = arr[i];
        int minInd = i;

        for(int j = i +1; j < n; j++){
            if(arr[j] < minVal){
                minVal = arr[j];
                minInd = j;
            }
        }
        if(minVal != arr[i]){
            swap(arr[i], arr[minInd]);
        }
    }
    cout<< "Selection Sort : "<<endl;
    for(auto i : arr){
        cout<< i << " ";
    }
}

int primMst(vector<vector<Edge>> adj){
    int n = adj.size();
    vector<bool> inMst(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    pq.push({0, 0});
    int total = 0;

    while(!pq.empty()){
        auto data = pq.top();
        pq.pop();
        
        int weight = data.first, node = data.second;
        
        if(inMst[node]) continue;
            
        inMst[node] = true;
        total += weight;
        for(auto n: adj[node]){
            if(!inMst[n.second]){
                pq.push(n);
            }
        }
    }

    return total;
}

struct Job{
    char id;
    int duration;
    int profit;
};

void jobScheduling(vector<Job> jobs){
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){return a.profit > b.profit;});
    int longestDuration = 0;
    for(auto j : jobs)
        longestDuration = longestDuration < j.duration ? j.duration : longestDuration;
    
    vector<char> slots(longestDuration, '\0');
    int totalProfit = 0;
    for(auto j : jobs){
        for(int i = j.duration - 1; i >= 0; i--){
            if(slots[i] == '\0'){
                slots[i] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    cout<<"Job Scheduled : ";
    for(auto s : slots){
        if(s != '\0') cout<< s << " ";
    }
    cout << endl << "Total Profit is : "<< totalProfit <<endl;
}

int main(){
    vector<int> arr = {5, 6, 2, 7, 1};
    selectionSort(arr);
    vector<vector<Edge>> graph(4);

    graph[0].push_back({4, 1});
    graph[0].push_back({1, 2});
    graph[1].push_back({4, 0});
    graph[1].push_back({3, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({1, 0});
    graph[2].push_back({3, 1});
    graph[2].push_back({4, 3});
    graph[3].push_back({2, 1});
    graph[3].push_back({4, 2});

    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                        {'d', 1, 25}, {'e', 3, 15}};

    cout << endl << "Total cost of MST: " << primMst(graph) << endl;
    jobScheduling(jobs);
    return 0;
}