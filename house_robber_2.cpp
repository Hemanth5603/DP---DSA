#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int helper(vector<int>& nums) {

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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> t1, t2;
        for(int i=0;i<n;i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i != n-1) t2.push_back(nums[i]);
        }
        int maxi = max(helper(t1), helper(t2));
        return maxi;
    }
};