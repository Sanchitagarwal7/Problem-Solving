#include<bits/stdc++.h>
using namespace std;

bool findPath(Node* root, int target, string &path){
    //base case
    if(root==NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    
    path+='L';
    if(findPath(root->left, target, path)){
        return true;
    }
    path.pop_back();
    
    path+='R';
    if(findPath(root->right, target, path)){
        return true;
    }
    path.pop_back();
    
    return false;
}

int findDist(Node* root, int a, int b) {
    string getPathA = "", getPathB = "";
    
    findPath(root, a, getPathA);
    findPath(root, b, getPathB);
    
    reverse(getPathA.begin(), getPathA.end());
    reverse(getPathB.begin(), getPathB.end());
    
    int i = getPathA.length()-1, j = getPathB.length()-1;
    while(i>=0 && j>=0 && getPathA[i]==getPathB[j]){
        getPathA.pop_back();
        getPathB.pop_back();
        i--;
        j--;
    }
    //make path and just return its size, that will be the number of steps from a to b
    string path = getPathA+getPathB;
    return path.length();
}

int main(){
    return 0;
}