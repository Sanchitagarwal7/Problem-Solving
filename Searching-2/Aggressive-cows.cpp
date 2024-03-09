#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int n, int k, int dist){
    int cows = 1;
    int prevStall = stalls[0];
    
    for(int i = 1; i<n; i++){
        if(stalls[i]-prevStall >= dist){
            cows++;
            prevStall = stalls[i];
        }
        if(cows==k){
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    
    int low = 1;
    int high = stalls[n-1]-stalls[0];
    
    int res = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(isPossible(stalls, n, k, mid)){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}

int main(){
    vector<int> stalls = {10, 1, 2, 7, 5};
    int n = 5;
    int k = 3;

    cout << solve(n, k, stalls) << endl;

    return 0;
}