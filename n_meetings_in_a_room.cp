//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool static compare(pair<int,int> a, pair<int,int> b){
      if(a.second < b.second){
          return true;
      }return false;
  }
    
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), compare);
        
        int last = v[0].second;
        
        int cnt = 1;
        for(int i=1;i<v.size();i++){
            if(v[i].first > last){
                cnt++;
                last = v[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends