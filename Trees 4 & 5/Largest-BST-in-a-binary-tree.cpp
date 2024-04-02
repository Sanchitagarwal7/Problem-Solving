#include<bits/stdc++.h>
using namespace std;


class Tree{
    public:
    bool bst;
    int size;
    int maxi;
    int mini;
};
Tree solve(Node* root, int &res){
    //base case
    if(root==NULL){
        // Tree* temp = new Tree(true, 0, -1e9, 1e9);
        return {true, 0, INT_MIN, INT_MAX};
    }
    
    Tree lSubtree = solve(root->left, res);
    Tree rSubtree = solve(root->right, res);
    
    Tree currNode;
    currNode.size = lSubtree.size + rSubtree.size + 1; //plus 1 for curr node
    if(root->data > lSubtree.maxi && root->data < rSubtree.mini && lSubtree.bst && rSubtree.bst){
        currNode.bst = true;
        res = max(res, currNode.size);
    }else{
        currNode.bst = false;
    }
    
    currNode.mini = min(root->data, lSubtree.mini);
    currNode.maxi = max(root->data, rSubtree.maxi);
    
    return currNode;
}
int largestBst(Node *root)
{
    int res = 0;
    Tree node = solve(root, res);
    return res;
}

int main(){
    return 0;
}