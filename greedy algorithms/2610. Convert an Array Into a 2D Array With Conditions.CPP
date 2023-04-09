// You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

// The 2D array should contain only the elements of the array nums.
// Each row in the 2D array contains distinct integers.
// The number of rows in the 2D array should be minimal.
// Return the resulting array. If there are multiple answers, return any of them.

// Note that the 2D array can have a different number of elements on each row.

 

// Example 1:

// Input: nums = [1,3,4,1,2,3,1]
// Output: [[1,3,4,2],[1,3],[1]]
// Explanation: We can create a 2D array that contains the following rows:
// - 1,3,4,2
// - 1,3
// - 1
// All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
// It can be shown that we cannot have less than 3 rows in a valid array.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: [[4,3,2,1]]
// Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= nums.length

// C++	
1
class Solution {
2
public:
3
    vector<vector<int>> findMatrix(vector<int>& nums) {
4
        unordered_map<int, int> mp;
5
        for(auto it: nums)
6
            mp[it]++;
7
        
8
        priority_queue<pair<int, int>> pq;
9
        for(auto it: mp)
10
        {
11
            pq.push({it.second, it.first});
12
        }
13
        int x = pq.top().first;
14
        
15
        vector<vector<int>>ans(x);
16
        while(!pq.empty())
17
        {
18
            int x = pq.top().first;
19
            int y = pq.top().second;
20
            
21
            pq.pop();
22
            
23
            for(int i=0;i<x;i++)
24
            {
25
                ans[i].push_back(y);
26
            }
27
        }
28
        return ans;
29
    }
30
};
