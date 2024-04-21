#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

    if(q.empty()) return {};

    int courseCompleted = 0;

    vector<int> courses;

    while(!q.empty()){
        auto temp = q.front(); q.pop();
        courses.push_back(temp);
        courseCompleted++;

        for(auto adjNode: adjList[temp]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }

    if(courseCompleted!=numCourses) return {};

    return courses;
}

int main(){
    return 0;
}