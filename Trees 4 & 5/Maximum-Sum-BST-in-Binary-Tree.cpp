#include<bits/stdc++.h>
using namespace std;

class getInfo{
    public:
    int sum;
    int maxi;
    int mini;
    bool isBst;
};

getInfo solve(TreeNode* root, int &maxSum){
    //base case
    if(root==NULL){
        //{size, maxi, mini, validity}
        return {0, INT_MIN, INT_MAX, true};
    }

    getInfo lSubtree = solve(root->left, maxSum);
    getInfo rSubtree = solve(root->right, maxSum);

    getInfo currNode;
    currNode.sum = lSubtree.sum + rSubtree.sum + root->val;
    if(lSubtree.isBst && rSubtree.isBst && root->val > lSubtree.maxi && root->val < rSubtree.mini){
        currNode.isBst = true;
        maxSum = max(maxSum, currNode.sum);   //if everything good then calculate maxSum
    }else{
        currNode.isBst = false;
    }

    currNode.mini = min(root->val, lSubtree.mini);
    currNode.maxi = max(root->val, rSubtree.maxi);

    return currNode;
}

int maxSumBST(TreeNode* root) {
    int maxSum = 0;
    getInfo node = solve(root, maxSum);
    return maxSum;
}

int main(){
    return 0;
}