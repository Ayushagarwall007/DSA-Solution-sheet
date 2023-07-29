#include<bits/stdc++.h>
vector<vector<int>> subarraysWithSumK(vector < int > a, long long k) {

    int n = a.size();

    vector<vector<int>> ans;
    // This will keep all those sub-arrays whose sum = ‘k’.

    // start and end are the starting 
    // and the ending indices of our current
    // subarray
    int start = 0, end = -1;
    long long currentSum = 0;

    // Iterating over 'a'
    while (start < n) {

        // Increasing the right end
        // till our sum <= ‘k’ or we 
        // are not out of bounds
        while ((end + 1 < n) && (currentSum + a[end + 1] <= k)) {
            currentSum += a[end + 1];
            ++end;
        }

        // We have found a subarray with the
        //  required sum.
        if (currentSum == k) {
            vector<int> temp;
            
            for(int i = start; i <= end; ++i) {
                temp.push_back(a[i]);
            }
            ans.push_back(temp);
        }

        // Shifting the start index
        currentSum -= a[start];
        ++start;
    }

    return ans;
}
