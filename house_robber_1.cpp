#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Recursion Solution

    int func(int ind, vector<int> nums, vector<int> &dp){
        if(ind == 0) return nums[ind];

        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + func(ind-2, nums, dp);
        int npick = 0 + func(ind-1, nums, dp);

        return dp[ind] =  max(pick, npick);
    }

    int rob(vector<int>& nums) {

        // Solution with Tabulation with space optimization o(n), o(1);
        int n = nums.size();
        vector<int> dp(n, -1);
        int prev = nums[0];
        int prev2 = 0;
        for(int i =1;i<n;i++){
            int pick = nums[i];
            if(i > 1) pick+= prev2;

            int nPick = 0 + prev;
            int curr = max(pick, nPick);
            prev2 = prev;
            prev = curr;

        }

        return prev;
    }
};