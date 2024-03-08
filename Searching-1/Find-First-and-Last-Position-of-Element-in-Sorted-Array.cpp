#include<bits/stdc++.h>
using namespace std;

    int firstOcc(vector<int>& nums, int target, int &n)
    {
        int low = 0;
        int high = n-1;

        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid]==target)
            {
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]>target)
            {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int target, int &n)
    {
        int low = 0;
        int high = n-1;

        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid]==target)
            {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        return {firstOcc(nums, target, n), lastOcc(nums, target, n)};
    }

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int n = 6;
    int target = 8;

    vector<int> res = searchRange(nums, n, target);

    for(auto it: res){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}