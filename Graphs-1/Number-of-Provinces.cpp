#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, int node)
{
    vis[node] = 1;      //mark visited 

    for(int i = 0; i<adj[node].size(); i++)     //iterate over its neighbours
    {
        if(!vis[adj[node][i]])  //if any1 is not visited
        {
            dfs(adj, vis, adj[node][i]); 
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();

    vector<int> adj[V];      //first make adjacency list 

    for(int i = 0; i<V; i++)
    {
        for(int j = 0; j<V; j++)
        {
            if(isConnected[i][j] == 1 && (i!=j))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> visited(V, 0);     

    int cnt = 0;

    for(int i = 0; i<V; i++)
    {
        if(!visited[i])     //if a node is not visited that means thats a distinct province
        {
            //because this will mark every node connected to current node as visited
            dfs(adj, visited, i);   

            cnt++;       //increment cnt here then
        }
    }

    return cnt;
}

int main(){
    return 0;
}