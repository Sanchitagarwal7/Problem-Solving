#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& bloomDay, int &m, int &k, int days){
    int flowers = 0;
    int bouquets = 0;

    for(int i = 0; i<bloomDay.size(); i++){
        if(bloomDay[i]<=days){
            flowers++;
            if(flowers==k){
                bouquets++;
                flowers = 0;
            }
        }else{
            flowers=0;
        }
        if(bouquets==m) return true;
    }

    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int low = 1;
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    int res = -1;
    while(low<=high){
        int mid = low+(high - low)/2;

        if(isPossible(bloomDay, m, k, mid)){
            res = mid;
            high = mid-1; //need to find the minimum days
        }else{
            low = mid+1;
        }
    }
    return res;
}
int main(){
    vector<int> nums = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    cout << minDays(nums, m, k) << endl;
    return 0;
}