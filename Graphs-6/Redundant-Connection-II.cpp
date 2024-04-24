#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> parent, size;

        DisjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);

            for(int i = 0; i<n; i++){
                parent[i] = i;
            }
        }

        int findPar(int u){
            if(parent[u]==u) return u;

            return parent[u] = findPar(parent[u]);
        }

        void unionBySize(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_u == ult_v) return ;
            if(size[ult_v] <= size[ult_u]){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }else if(size[ult_u] < size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
        }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    int maxIndegree = -1e9;
    vector<int> indegree(n+1, 0);

    int edge1 = -1;
    int edge2 = -1;

    DisjointSet * ds = new DisjointSet(n+1);

    for(auto it: edges){
        int u = it[0];
        int v = it[1];

        indegree[v]++;
        maxIndegree = max(maxIndegree, indegree[v]);
    }

    for(int i = 0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        if(indegree[v]==2){
            if(edge1==-1){
                edge1 = i;
            }else{
                edge2 = i;
                break;
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(edge2==i) continue; //extra edge ko skip krte h

        int u = edges[i][0];
        int v = edges[i][1];

        if(ds->findPar(u)!=ds->findPar(v)){
            ds->unionBySize(u, v);
        }else{  //still cycle is found
            if(edge1!=-1){  
                return edges[edge1];    //extra edge ko skip krne k baad bhi loop ban rha h toh edge1 redundant edge h
            }else{
                return edges[i];    //wrna agr sbki indegree <= 1 hai toh the current edge hi extra h
            }
        }
    }

    return edges[edge2];    //lastly agr loop nahi bna toh edge2 hi extra edge hai
}

int main(){
    return 0;
}