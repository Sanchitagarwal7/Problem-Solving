#include<bits/stdc++.h>
using namespace std;

bool check(TreeNode* root,  TreeNode* mini,  TreeNode* maxi){
    //base case
    if(root==NULL){
        return true;
    }
    if((mini!=NULL && root->val <= mini->val) || (maxi!=NULL && root->val >= maxi->val)){
        return false;
    }

    return check(root->left, mini, root) && check(root->right, root, maxi);
}
bool isValidBST(TreeNode* root) {
    //we will go with range approach
    TreeNode* mini = NULL;
    TreeNode* maxi = NULL;

    return check(root, mini, maxi);
}

int main(){
    return 0;
}