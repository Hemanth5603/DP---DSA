//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int solve(int ind, int price[], int n, vector<vector<int>> &dp){
        if(ind == 0){
            return n * price[0];
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        int ntake = 0 + solve(ind-1, price, n, dp);
        int take = INT_MIN;
        int rodL = ind + 1;
        if(rodL <= n){
            take = price[ind] + solve(ind, price, n - rodL, dp);
        }
        return dp[ind][n] = max(ntake, take);
    }
  
    int cutRod(int price[], int n){
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends