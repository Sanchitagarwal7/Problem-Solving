#include<bits/stdc++.h>
using namespace std;

unordered_map<Node*, Node* > mp;
Node* cloneGraph(Node* node) {
    if(node==NULL) return node;

    Node* cloneNode = new Node(node->val);
    mp[node] = cloneNode;

    for(auto adj: node->neighbors){
        if(mp.find(adj)==mp.end()){
            cloneGraph(adj);
        }
        cloneNode->neighbors.push_back(mp[adj]);
    }

    return cloneNode;
}

int main(){
    return 0;
}