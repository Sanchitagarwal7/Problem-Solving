#include<bits/stdc++.h>
using namespace std;
int getLevelDiff(Node *root)
    {
        
        long long evenSum = 0;
        long long oddSum = 0;
        
        int level = 0;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                auto temp = q.front(); q.pop();
                
                if(level%2==0){
                    evenSum += temp->data;
                }else{
                    oddSum += temp->data;
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            level++;
        }
        
        return evenSum-oddSum;
    }
int main(){
    return 0;
}