#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> adjList[n];
    unordered_map<int, set<int>> nodeToAncestors;
    vector<int> indegree(n, 0);

    for(auto it: edges){
        int u = it[0];
        int v = it[1];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<vector<int>> res(n);

    for(int i = 0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto node = q.front(); q.pop();

        for(auto adjNode: adjList[node]){
            if(indegree[adjNode] > 0){ 
                indegree[adjNode]--;
                for(auto p: nodeToAncestors[node]){ //push parents ancestors
                    nodeToAncestors[adjNode].insert(p);
                }
            }
            nodeToAncestors[adjNode].insert(node);  //push current node as ancestor
            if(indegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }

    for(auto it: nodeToAncestors){
        for(auto jt: it.second){
            res[it.first].push_back(jt);
        }
    }

    return res;
}

int main(){
    return 0;
}