#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    int low = 0;
    int high = n-1;

    //edge case
    if(low==high) return nums[low];

    while(low<=high){
        int mid = low+(high-low)/2;

        if(mid==0 && nums[mid+1]!=nums[mid] || mid==n-1 && nums[mid-1]!=nums[mid]){
            return nums[mid];
        }
        else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return nums[mid];
        }else if((nums[mid-1]==nums[mid] && (mid-1)%2!=0) || (nums[mid]==nums[mid+1] && mid%2!=0)){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec = {1,1,2,3,3,4,4,8,8};

    cout << singleNonDuplicate(vec) << endl;

    return 0;
}