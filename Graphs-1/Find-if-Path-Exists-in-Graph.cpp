#include<bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //make adjacency list
    vector<int> adjList[n];

    for(auto it: edges)
    {
        int u = it[0];
        int v = it[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<int> q;
    vector<int> vis(n, false);
    q.push(source);
    vis[source] = true;

    while(!q.empty()){
        auto temp = q.front(); q.pop();

        if(temp == destination)
            return true;

        for(auto adjNode: adjList[temp])
        {
            if(!vis[adjNode])
            {
                vis[adjNode] = true;
                q.push(adjNode);
            }
        }
    }

    return false; 
}

int main(){
    return 0;
}