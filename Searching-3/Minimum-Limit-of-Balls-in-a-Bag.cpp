#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int maxOperations, int penalty){
    int count = 0;
    if(penalty==0) return false;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]%penalty==0){
            count += nums[i]/penalty-1;
        }else{
            count += nums[i]/penalty;
        }
    }

    return count <= maxOperations;
}
int minimumSize(vector<int>& nums, int maxOperations) {
    int low = 0;
    int high = *max_element(nums.begin(), nums.end());

    int res;
    while(low<=high){
        int mid = low+(high-low)/2;

        if(isPossible(nums, maxOperations, mid)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {2,4,8,2};
    int ops = 4;

    cout << minimumSize(nums, ops) << endl;
    return 0;
}