#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[7] = {4,5,6,7,0,1,2};
    int n = 7;
    int target = 0;

    int low = 0;
    int high = n-1;

    int res = -1;

    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(nums[mid]==target){
            res = mid;
            break;
        }else if(nums[mid] >= nums[0]){
            if(target >= nums[0] && nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(target < nums[0] && nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }

    cout << res << endl;

    return 0;
}