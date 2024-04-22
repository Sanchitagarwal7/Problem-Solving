#include<bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.length();

    vector<int> indegree(n, 0);
    vector<int> adjList[n];

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q; //<node, max color frequency in that path>
    int maxFreq = 0; //at least 1 color node exists

    for(int i = 0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //there is cycle if queue is empty
    if(q.empty()){
        return -1;
    }

    int countNodes = 0; //check if all nodes are visited or not, if not //there is cycle somewhere
    vector<vector<int>> tillNodeColor(n, vector<int>(26, 0));

    while(!q.empty()){
        auto node = q.front(); q.pop();
        countNodes++;

        tillNodeColor[node][colors[node]-'a']++; //increment color freq till this node
        maxFreq = max(maxFreq, tillNodeColor[node][colors[node]-'a']); //compare with max freq of color

        for(auto adjNode: adjList[node]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0){
                q.push(adjNode);
            }

            for(int i = 0; i<26; i++){
                tillNodeColor[adjNode][i] = max( tillNodeColor[adjNode][i], tillNodeColor[node][i] ); //max because maybe we visit that same node with another path
            }
        }
    }

    if(countNodes!=n){
        return -1;
    }
    
    return maxFreq;
}

int main(){
    return 0;
}