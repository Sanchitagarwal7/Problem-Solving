#include<bits/stdc++.h>
using namespace std;

int heightOfBinaryTree(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; i++){
            auto temp = q.front(); q.pop();

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        level++;
    }

    return level;
}

int main(){
    return 0;
}