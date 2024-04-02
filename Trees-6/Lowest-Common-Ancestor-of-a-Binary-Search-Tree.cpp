#include<bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //base case
    if(root==NULL){
        return root;
    }
    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;    //this the lca
}

int main(){
    return 0;
}