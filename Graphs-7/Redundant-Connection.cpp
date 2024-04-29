#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public:
        vector<int> parent, size;

        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = findParent(parent[u]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v) return ;
            else if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    
};


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    DisjointSet *ds = new DisjointSet(n+1);
    vector<int> res(2);

    for(int i = 0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        if(ds->findParent(u) != ds->findParent(v)){
            ds->unionBySize(u, v);
        }else{
            res[0] = u;
            res[1] = v;
        }
    }

    return res;
}

int main(){
    return 0;
}