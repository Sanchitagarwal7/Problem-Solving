#include<bits/stdc++.h>
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    vector<pair<int, int>> adjList[n];
    
    vector<int> dist(n);
    for(int i = 0; i<n; i++) dist[i] = disappear[i];
    //dist is ready
    
    vector<int> weight(n);
    
    for(auto it: edges){
        auto u = it[0];
        auto v = it[1];
        auto w = it[2];
        
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    //adjList is ready
    
    
    //apply djistra
    set<pair<int, int>> minHeap;
    minHeap.insert({0, 0});
    dist[0] = 0; //time is 0
    
    while(!minHeap.empty()){
        auto temp = *(minHeap.begin()); minHeap.erase(temp);
        
        int w = temp.first;
        int node = temp.second;
        
        for(auto adj: adjList[node]){
            auto adjNode = adj.first;
            auto adjW = adj.second;
            
            if(dist[adjNode] > dist[node]+adjW){
                
                if(dist[adjNode] != disappear[adjNode]) 
                    minHeap.erase({dist[adjNode], adjNode}); 
                
                dist[adjNode] = dist[node]+adjW;
                minHeap.insert({dist[adjNode], adjNode});
            }
        }
    }
                
    vector<int> res(n);

    for(int i = 0; i<n; i++){
        if(disappear[i]>dist[i]){
            res[i] = dist[i];
        }else{
            res[i] = -1;
        }
    }

    return res;
}

int main(){
    return 0;
}