#include<bits/stdc++.h>
using namespace std;

void inorder(Node* root, vector<int> &vec){
    //baes case
    if(root==NULL){
        return ;
    }
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}
    
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    
    vector<int> v3(v1.size()+v2.size());
    int index = 0;
    int i = 0;
    int j = 0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            v3[index++] = v1[i++];
        }else{
            v3[index++] = v2[j++];
        }
    }
    while(i<v1.size()){
        v3[index++] = v1[i++];
    }
    while(j<v2.size()){
        v3[index++] = v2[j++];
    }
    
    return v3;
}

int main(){
    return 0;
}