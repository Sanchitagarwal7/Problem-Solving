#include<bits/stdc++.h>
using namespace std;

/*RECURSION*/
// int solve(vector<int> &nums, int index, vector<int>&mx, int &n, int &x, int &y, int &z){
//     //base case
//     if(mx.size()==3){
//         int ans;
//         ans = (x * mx[0]) + (y * mx[1]) + (z * mx[2]);
//         return ans;
//     }
//     if(index>=n) return INT_MIN;

//     //non-pick
//     int nonPick = solve(nums, index+1, mx, n, x, y, z);

//     mx.push_back(nums[index]);
//     int pick = solve(nums, index, mx, n, x, y, z);
//     mx.pop_back();

//     return max(pick, nonPick);
// }

// int main(){
//     int n, x, y, z;
//     cin >> n >> x >> y >> z;

//     vector<int> nums(n);
//     for(int i = 0; i<n; i++){
//         cin >> nums[i];
//     }

//     vector<int> maxNums;
//     int index = 0;

//     cout << solve(nums, index, maxNums, n, x, y, z) << endl;

//     return 0;
// }

/*BOTTOM-UP*/
int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    //need to pick any integer whose product give max answer, since we can take same number multiple times
    //x*a[i] , y*a[i] , z*a[i] are not dependent on each other

    int firstTerm = x*nums[0];
    int secondTerm = y*nums[0];
    int thirdTerm = z*nums[0];

    for(int i = 1; i<n; i++){
        firstTerm = max(firstTerm, x*nums[i]);
        secondTerm = max(secondTerm, y*nums[i]);
        thirdTerm = max(thirdTerm, z*nums[i]);
    }

    cout << firstTerm+secondTerm+thirdTerm << endl;

    return 0;
}