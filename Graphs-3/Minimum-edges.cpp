#include<bits/stdc++.h>
using namespace std;

int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
{
    int m = edges[0].size();
    
    vector<pair<int, int>> adjList[n+1];
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        
        adjList[u].push_back({v, 0}); //normal edge
        adjList[v].push_back({u, 1}); //reversed edge
    }
    
    //need to make minHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    minheap.push({0, src}); //{reverse edges till node, node}
    
    
    vector<int> dist(n+1, 1e9); //we want minimum reversed edges to reach node
    dist[src] = 0;
    
    while(!minheap.empty()){
        auto temp = minheap.top(); minheap.pop();
        
        int rev = temp.first;
        int node = temp.second;
        
        for(auto adj: adjList[node]){
            int adjNode = adj.first;
            int edge = adj.second;
            
            if(dist[adjNode] > rev+edge){
                dist[adjNode] = rev+edge;
                minheap.push({dist[adjNode], adjNode});
            }
        }
    }
    
    return dist[dst]==1e9 ? -1 : dist[dst];
}

int main(){
    return 0;
}