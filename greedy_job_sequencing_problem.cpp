#include<bits/stdc++.h>

using namespace std;
static bool compare(vector<int>a, vector<int>b) {
    return (a[2] > b[2]);
}

vector<int> jobScheduling(vector<vector<int>> &jobs){

    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),compare);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(jobs[i][1]>maxi){
                maxi=jobs[i][1];
            }
        }

        vector<bool>papa(maxi,false);

        int sum=0;

        int count=0;

        for(int i=0;i<n;i++)

        {

           int deadline=jobs[i][1];

           for(int j=deadline;j>=1;j--)

            {

                if(papa[j-1]==false)

                {

                sum+=jobs[i][2];

                count++;

                papa[j-1]=true;

                break;

                }

            }

        }

       

        return {count,sum};

    } 