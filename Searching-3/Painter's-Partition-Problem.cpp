#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k, int time){
    int timeTook = 0;
    int painter = 1;

    for(int i = 0; i<boards.size(); i++){
        timeTook += boards[i];

        if(timeTook > time){
            painter++;
            timeTook = boards[i];

            if(painter > k || boards[i] > time) return false;
        }
    }

    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = 1;
    int high = 0;
    for(auto it: boards){
        high+=it;
    }

    int res = high;
    while(low<=high){
        int mid = low+(high-low)/2;

        if(isPossible(boards, k, mid)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    int k = 2;

    cout << findLargestMinDistance(nums, k) << endl;
    
    return 0;
}