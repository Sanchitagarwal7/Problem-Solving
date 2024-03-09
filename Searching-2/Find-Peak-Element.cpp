#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    int low = 0;
    int high = n-1;

    //edge case
    if(low==high) return low;

    while(low<=high){
        int mid = low+(high-low)/2;

        //first index is peak
        if(mid==0 && nums[mid]>nums[1]){
            return mid;
        }
        //last index is peak
        if(mid==n-1 && nums[n-2]<nums[mid]){
            return mid;
        }

        if((mid-1>=0 && nums[mid-1] < nums[mid]) && (mid+1 < n && nums[mid] > nums[mid+1])){
            return mid;
        }else if(mid-1>=0 && nums[mid-1] > nums[mid]){
            high = mid-1;
        }else if(mid+1 < n && nums[mid+1 > nums[mid]]){
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> vec = {1,2,1,3,5,6,4};

    cout << findPeakElement(vec) << endl;
    return 0;
}