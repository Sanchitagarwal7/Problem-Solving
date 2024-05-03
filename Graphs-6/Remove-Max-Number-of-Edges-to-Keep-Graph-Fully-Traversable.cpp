#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public:
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i<n; i++){
                parent[i] = i;
            }
        }
        int findPar(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u] = findPar(parent[u]);
        }
        bool unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if(ult_u==ult_v) return false;
            if(rank[ult_u] > rank[ult_v]){
                parent[ult_v] = ult_u;
            }else if(rank[ult_v] > rank[ult_u]){
                parent[ult_u] = ult_v;
            }else{
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
            return true;
        }
};

static bool cmp(vector<int> &a, vector<int> &b){
    return a[0] > b[0];
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    //first we sort the edges so that tyoe 3 edges are made so that both alice and both can traverse
    sort(edges.begin(), edges.end(), cmp);

    //make two disjoint sets for both alice and bob can traverse
    //also count edges traversed by alice and bob separately
    //if both edges individually == n-1, they can traverse whole graph, else -1
    //if we upon an edge that connects already connected components then add to count edges that need to be removed
    DisjointSet* alice = new DisjointSet(n+1);
    DisjointSet* bob = new DisjointSet(n+1);
    int aliceEdges = 0, bobEdges = 0, count = 0;
    for(auto it: edges){
        int type = it[0];
        int u = it[1];
        int v = it[2];
        if(type==3){
            if(alice->unionByRank(u, v)){
                bob->unionByRank(u, v);
                aliceEdges++;
                bobEdges++;
            }else{
                count++;
            }
        }else if(type==1){
            if(alice->unionByRank(u, v)){
                aliceEdges++;
            }else{
                count++;
            }
        }else{
            if(bob->unionByRank(u, v)){
                bobEdges++;
            }else{
                count++;
            }
        }
    }
    if(aliceEdges==n-1 && bobEdges==n-1){
        return count;
    }else{
        return -1;
    }
}

int main(){
    return 0;
}