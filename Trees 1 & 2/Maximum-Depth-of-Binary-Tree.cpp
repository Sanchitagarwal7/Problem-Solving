#include<bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode* root) {
        //base case
        if(root==NULL)
        {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth)+1; 
}

int main(){
    return 0;
}