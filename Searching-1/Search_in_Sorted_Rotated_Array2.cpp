#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[7] = {2,5,6,0,0,1,2};
    int n = 7;
    int target = 3;

    int low = 0;
    int high = n-1;

    bool res = false;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[mid]==target){
            res = true;
            break;
        }
        else if(nums[mid] > nums[low]){
            if(target >= nums[low] && target < nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else if(nums[mid]==nums[low]){
            low++;
        }else{
            if(target < nums[low] && target > nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }

    if(!res){
        cout << "Not Found" << endl;
    }else{
        cout << "Found" << endl;
    }

    return 0;
}