#include<bits/stdc++.h>
using namespace std;

bool solve(int *preorder, int &size){
    //if one child then parent and child will differ from 1 index

    //let range of first elemement be between (-1e9, element-1), (element+1, 1e9) inclusive;
    int lmini = -1e9;
    int lmaxi = preorder[0]-1;
    int rmini = preorder[0]+1;
    int rmaxi = 1e9;

    for(int node = 1; node<size-1; node++){
        int left = preorder[node];
        int right = preorder[node+1];

        if(left >= lmini && left <= lmaxi){
            //left child exists
            if(right >= rmini && right <= rmaxi){
                //two child cant exist
                return false;
            }
            lmaxi = left-1;
            rmini = left+1;
        }else if(right >= rmini && right <= rmaxi){
            //right child exists, then left child didnt exists otherwise it would go to first if-block
            rmini = right+1;
            lmaxi = right-1;
        }
    }
    return true;
}

int main(){
    int pre[] = { 20, 10, 11, 13, 12 }; //{8, 3, 5, 7, 6} tc: 2
    int size = sizeof(pre) / sizeof(pre[0]);
     
    if (solve(pre,size))
        cout <<"Yes";
    else
        cout <<"No";
         
    return 0;
}