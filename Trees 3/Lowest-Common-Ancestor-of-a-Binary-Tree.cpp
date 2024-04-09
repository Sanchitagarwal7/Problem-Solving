#include<bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)return root;
    if(root == p || root == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left!=NULL && right==NULL){
        return left;
    }
    if(left==NULL && right!=NULL){
        return right;
    }

    return NULL;
}

int main(){
    return 0;
}