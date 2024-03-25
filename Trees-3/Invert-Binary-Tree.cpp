#include<bits/stdc++.h>
using namespace std;

TreeNode* invertTree(TreeNode* root) {
    //bae case
    if(root==NULL) return NULL;

    TreeNode* leftSubtree = invertTree(root->left);
    TreeNode* rightSubtree = invertTree(root->right);

    root->left = rightSubtree;
    root->right = leftSubtree;

    return root;
}

int main(){
    return 0;
}