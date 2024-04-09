#include<bits/stdc++.h>
using namespace std;

void inorder(Node* root, Node* &prev){
    //bae case
    if(root==NULL){
        return ;
    }
    
    //left call
    inorder(root->left, prev);

    //make it doubly
    if(prev!=NULL){
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    
    //right call
    inorder(root->right, prev);
}

void leftRecur(Node* root, Node* &head){
    //base case
    if(root==NULL){
        return ;
    }
    
    head = root;
    
    //left call till we reach leftmost node
    leftRecur(root->left, head);
}

void rightRecur(Node* root, Node* &tail){
    //base case
    if(root==NULL){
        return ;
    }
    
    tail = root;
    
    //left call till we reach leftmost node
    rightRecur(root->right, tail);
}
Node *bTreeToCList(Node *root)
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* prev = NULL;
    
    //get head
    leftRecur(root, head);
    //get tail
    rightRecur(root, tail);
    
    inorder(root, prev);
    
    //make it circular
    head->left = tail;
    tail->right = head;
    
    return head;
}

int main(){
    return 0;
}