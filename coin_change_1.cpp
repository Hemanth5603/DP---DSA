
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int ind, int t, vector<int> &coins, vector<vector<int>> &dp){
        if(ind == 0){
            if(t % coins[ind] == 0) return t/coins[0];
            return 1e9;
        }
        if(dp[ind][t] != -1) return dp[ind][t];
        int npick = solve(ind -1, t, coins, dp);
        int pick = INT_MAX;
        if(coins[ind] <= t){
            pick = 1 + solve(ind, t - coins[ind], coins, dp);
        }

        return dp[ind][t] = min(npick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};