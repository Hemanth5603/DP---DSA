#include <bits/stdc++.h> 
using namespace std;


// Memoization code
bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = solve(ind-1, target, arr, dp);
    bool take = false;

    if(arr[ind] <= target) take = solve(ind-1,target - arr[ind], arr, dp);

    return dp[ind][target] = take | notTake;

    
}

// tabulation code

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n, vector<bool>(k+1, 0));
    for(int i=0;i<n;i++) dp[i][0] = true;

    dp[0][arr[0]] = true;
    for(int ind = 1;ind <n;ind++){
        for(int target = 1; target <=k;target++){
            bool notTake = dp[ind-1][target];
            bool take = false;

            if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }

    return dp[n-1][k];



    
}