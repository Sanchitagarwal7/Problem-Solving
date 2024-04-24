#include<bits/stdc++.h>
using namespace std;

int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<int> adjList[n];

    for(auto it: edges){
        int u = it[0];
        int v = it[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int shortest = 1e9;

    for(int i = 0; i<n; i++){ //for connected components
        vector<int> dist(n, 1e9);
        vector<int> par(n, -1);
        queue<pair<int, int>> q;

        q.push({0, i});
        dist[i] = 0;

        while(!q.empty()){
            auto temp = q.front(); q.pop();

            int dN = temp.first;
            int node = temp.second;

            for(auto adj: adjList[node]){

                if(dist[adj]==1e9){
                    //not visited
                    par[adj] = node;
                    dist[adj] = dN+1;
                    q.push({dist[adj], adj});
                }else if(par[adj]!=node && par[node]!=adj){ //adjacent ka parent koi aur h && aur current ka parent adjacent nahi h, mtlb same edge pr nahi h
                    shortest = min(shortest, dist[node]+dist[adj]+1);
                }
            }
        }
    }

    if(shortest==1e9) return -1; //not found

    return shortest;
}

int main(){
    return 0;
}