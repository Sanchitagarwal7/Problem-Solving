#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> &vis,vector<bool> &samePath,  int node){
    
    vis[node] = true;
    samePath[node] = true;
    
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(dfs(adj, vis, samePath, adjNode)){
                return true;
            }
        }else if(samePath[adjNode]){    //if visited on saem path then its a cycle, otherwise adjNode could be visited in some other path before node which led to no cycle
            return true;
        }
    }
    
    samePath[node] = false;
    
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<bool> samePath(V, false);
    
    for(int u = 0; u<V; u++){
        if(!vis[u]){
            if(dfs(adj, vis, samePath, u)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    return 0;
}