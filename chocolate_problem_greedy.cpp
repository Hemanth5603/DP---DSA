// Problem statement
// Given an array/list of integer numbers 'CHOCOLATES' of size 'N', where each value of the array/list represents the number of chocolates in the packet. There are ‘M’ number of students and the task is to distribute the chocolate to their students. Distribute chocolate in such a way that:

// 1. Each student gets at least one packet of chocolate.

// 2. The difference between the maximum number of chocolate in a packet and the minimum number of chocolate in a packet given to the students is minimum.

// And chocolates in each packet is : {8, 11, 7, 15, 2}

// magical intution



#include <bits/stdc++.h> 


using namespace std;
int findMinDiff(int n, int m, vector<int> choco) {
    sort(choco.begin(), choco.end());
    int i = 0;
    int j = m-1;
    int mini = INT_MAX;

    while(j<n){
        int diff = choco[j] - choco[i];
        mini = min(diff, mini);
        i++;
        j++;

    }
    return mini;

}


