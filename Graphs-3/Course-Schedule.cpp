#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<int> adjList[numCourses];
    vector<int> indegree(numCourses, 0);

    for(auto it: prerequisites){
        int u = it[1];
        int v = it[0];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i<numCourses; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    if(q.empty()) return false;

    int courseCompleted = 0;

    while(!q.empty()){
        auto temp = q.front(); q.pop();
        courseCompleted++;

        for(auto adjNode: adjList[temp]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }

    if(courseCompleted!=numCourses) return false;

    return true;
}

int main(){
    return 0;
}