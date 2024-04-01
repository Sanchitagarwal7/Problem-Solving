#include<bits/stdc++.h>
using namespace std;

void leftT(TreeNode<int>* root, vector<int> &res){
    //base case
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return ;
    }

    res.push_back(root->data);
    if(root->left)
        leftT(root->left, res);
    else
        leftT(root->right, res);
}

void subtree(TreeNode<int>* root, vector<int> &res){
    //base case
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL){
        res.push_back(root->data);
        return ;
    }
    subtree(root->left, res);
    subtree(root->right, res);
}

void rightT(TreeNode<int>* root, vector<int> &res){
    //base case
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return ;
    }

    if(root->right)
        rightT(root->right, res);
    else
        rightT(root->left, res);

    //need in reverse order -> tail recursion
    res.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    res.push_back(root->data);
    //left traversal
    leftT(root->left, res);
    //left subtree leaf nodes
    subtree(root->left, res);
    //right subtree leaf nodes
    subtree(root->right, res);
    //right traversal in reverse order
    rightT(root->right, res);

    return res;
}

int main(){
    return 0;
}