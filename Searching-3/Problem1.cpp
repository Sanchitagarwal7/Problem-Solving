#include<bits/stdc++.h>
using namespace std;

bool isPossible(int *arr, int n, int sum, int subSize){

    for(int i = 0; i<=n-subSize; i++){
        
        int len = i+subSize;
        int subSum = 0;

        for(int j = i; j<len; j++){
            subSum+=arr[j];
        }

        if(subSum > sum){
            return false;
        }
    }
    return true;
}

int solve(int *arr, int sum, int n){
    int low = 1;
    int high = n;

    int res = 0;

    while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(arr, n, sum, mid)){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return res;
}

int main(){
    int arr[4] = {1, 3, 4, 2};
    int sum = 7;

    cout << solve(arr, sum, 4) << endl;
    return 0;
}