#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int ind, int &n, vector<int>& nums, vector<int>& dp){
        
        if(ind >= n-1) return 0;
        
        if(dp[ind] != -1) return dp[ind];

        int minJumps = n+1;

        for(int i=nums[ind];i>=1;i--){
            int jumps = 1 + solve(ind + i, n, nums, dp);
            minJumps = min(jumps, minJumps);
        }
        return dp[ind] = minJumps;
    }


    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);

        for(int i= n-2;i >= 0;i--){
            int minJumps = n+1;
            for(int steps=nums[i];steps>=1;steps--){
                int jumps = 1;
                if(i + steps >= n -1){
                    jumps = 1;
                }else{
                    jumps = 1 + dp[i+steps];
                }
               
                minJumps = min(jumps, minJumps);
            }
            dp[i] = minJumps;
        }
        return dp[0];

        
    }
};