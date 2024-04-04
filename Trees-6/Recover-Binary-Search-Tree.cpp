#include<bits/stdc++.h>
using namespace std;

void inorder(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
    //base case
    if(root==NULL){
        return ;
    }
    //left call
    inorder(root->left, first, second, prev);
    //processing
    if(prev!=NULL && root->val < prev->val){
        if(first==NULL){
            first = prev;
        }
        second = root; //both nodes need to be swapped could be one after another
    }
    prev = root;
    //right call
    inorder(root->right, first, second, prev);
}

void recoverTree(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    inorder(root, first, second, prev);

    swap(first->val, second->val);
}

int main(){
    return 0;
}