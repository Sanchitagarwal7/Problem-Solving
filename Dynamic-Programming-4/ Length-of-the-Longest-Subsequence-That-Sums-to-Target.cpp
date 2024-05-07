#include<bits/stdc++.h>
using namespace std;

/*Space optimisation*/
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        
        int index = n-1;
        
        vector<int> prev(target+1, -1e8);
        vector<int> curr(target+1, -1e8);

        //base cases
        prev[0] = 0;
        for(int i = 0; i<target+1; i++)
        {
            if(nums[0] == i){
                prev[i] = 1;
            }
        }

        for(int ind = 1; ind<n; ind++)
        {
            curr[0] = 0;
            for(int tar = 0; tar<target+1; tar++)
            {
                //take
                int takeLength = -1e8;
                if(nums[ind]<=tar)
                {
                    takeLength = 1+prev[tar-nums[ind]];
                }
                //not take
                int notTake = prev[tar];
                
                curr[tar] = max(takeLength, notTake);
            }
            prev = curr;
        }
        
        if(prev[target] < 0) return -1;
        
        return prev[target];
    }
};

/*Tabulation*/
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        
        int index = n-1;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1e8));

        //base cases
        for(int i = 0; i<n; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i<target+1; i++)
        {
            if(nums[0] == i){
                dp[0][i] = 1;
            }
        }

        for(int ind = 1; ind<n; ind++)
        {
            for(int tar = 0; tar<target+1; tar++)
            {
                //take
                int takeLength = -1e8;
                if(nums[ind]<=tar)
                {
                    takeLength = 1+dp[ind-1][tar-nums[ind]];
                }
                //not take
                int notTake = dp[ind-1][tar];
                
                dp[ind][tar] = max(takeLength, notTake);
            }
        }
        
        if(dp[index][target] < 0) return -1;
        
        return dp[index][target];
    }
};

/*Memoization*/
class Solution {
public:
    int findLongest(vector<int>& nums, int target, int index, int &n, vector<vector<int>> &dp)
    {
        //base cases
        if(target == 0) return 0;
        if(index == 0){
            if(nums[0] == target)
            {
                return 1;
            }
            else
            {
                return -1e8;
            }
        }
        if(dp[index][target]!=-1) return dp[index][target];
        //take
        int takeLength = -1e8;
        if(nums[index]<=target)
        {
            takeLength = 1+findLongest(nums, target-nums[index], index-1, n, dp);
        }
        //not take
        int notTake = findLongest(nums, target, index-1, n, dp);
        
        return dp[index][target] = max(takeLength, notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        
        int index = n-1;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        int length = findLongest(nums, target, index, n, dp);
        
        if(length < 0) return -1;
        if(length == 0) return 1;
        
        return length;
    }
};

int main(){
    return 0;
}