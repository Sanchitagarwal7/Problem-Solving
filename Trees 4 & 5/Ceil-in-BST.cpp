#include<bits/stdc++.h>
using namespace std;

void preorder(Node* root, int &input, int &ans){
    //base case
    if(root==NULL){
        return ;
    }
    //calculate
    if(root->data < input){
        preorder(root->right, input, ans);
    }else{
        ans = root->data;
        preorder(root->left, input, ans);
    }
}

int findCeil(Node* root, int input) {
    int ans = -1;
    preorder(root, input, ans);
    return ans;
}

int main(){
    return 0;
}