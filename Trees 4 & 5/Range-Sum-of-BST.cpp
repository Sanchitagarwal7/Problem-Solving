#include<bits/stdc++.h>
using namespace std;

int rangeSumBST(TreeNode* root, int low, int high) {
    //base case
    if(root==NULL){
        return 0;
    }

    int sum = 0;
    if(root->val >= low && root->val <= high){
        sum+=root->val;
    }

    return sum + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main(){
    return 0;
}