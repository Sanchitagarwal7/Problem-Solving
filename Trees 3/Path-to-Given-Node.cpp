#include<bits/stdc++.h>
using namespace std;

bool dfs(TreeNode* A, int &B, vector<int> &path){
    //base case
    if(A==NULL) return false;
    if(A->val == B){
        path.push_back(B);
        return true;
    }
    
    path.push_back(A->val);
    
    if(dfs(A->left, B, path) || dfs(A->right, B, path)){
        return true;
    }
    
    path.pop_back();
    
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    
    dfs(A,B,path);
    
    return path;
}

int main(){
    return 0;
}