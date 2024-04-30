#include<bits/stdc++.h>
using namespace std;

void djikstra(vector<pair<int, int>> adjList[], vector<int> &dist, int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    minheap.push({0, src});
    dist[src] = 0;
    
    while(!minheap.empty()){
        auto temp = minheap.top(); minheap.pop();
        
        int w = temp.first;
        int node = temp.second;
        
        for(auto adj: adjList[node]){
            int adjNode = adj.first;
            int edgeW = adj.second;
            
            if(dist[adjNode] >= w+edgeW){
                
                dist[adjNode] = w+edgeW;
                
                minheap.push({dist[adjNode], adjNode});
            }
        }
    }
}

vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    
    vector<pair<int, int>> adjList[n];
    
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    
    vector<int> dist1(n, 1e9);
    vector<int> dist2(n, 1e9);

    djikstra(adjList, dist1, 0);
    djikstra(adjList, dist2, n-1);

    //if min distance from (0, u) + edge weight between (u,v) + min distance from (v, n-1) === min distance from (0, n-1)
    //then it contributes in shortest path

    vector<bool> res(m, false);

    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(dist1[u] + w + dist2[v] == dist1[n-1]){
            res[i] = true;
        }

        if(dist1[v] + w + dist2[u] == dist1[n-1]){
            res[i] = true;
        }
    }
    
    return res;
}

int main(){
    return 0;
}