#include<bits/stdc++.h>
using namespace std;

void traverse(Node* root, set<int>&nodes){
    //base case
    if(root==NULL){
        return ;
    }
    
    nodes.insert(root->data);
    traverse(root->left, nodes);
    traverse(root->right, nodes);
}

vector <int> findCommon(Node *root1, Node *root2)
{
    set<int> t1, t2;
    traverse(root1, t1);
    traverse(root2, t2);
    
    vector<int> res;
    for(auto it: t1){
        if(t2.count(it)){
            res.push_back(it);
        }
    }
    
    return res;
}

int main(){
    return 0;
}