#include<bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n) {
    int low = 0;
    int high = n-1;
    
    int ans = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(arr[mid] < arr[0]){
            ans = mid; //aur kam ho skta h
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    
    return ans;
}

int main(){
    int nums[5] = {5, 1, 2, 3, 4};
    int n = 5;

    cout << findKRotation(nums, n) << endl;
    
    return 0;
}