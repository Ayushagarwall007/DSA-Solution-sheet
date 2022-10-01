// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n
// Accepted
// 594.5K
// Submissions
// 903.1K
// Acceptance Rate
// 65.8%



class Solution {
public:
   vector<vector<int>>res;
    void find(int n,int k,int index,vector<int>&v)
    {
        if(k==0)
        {
            res.push_back(v);
            return;
        }
        for(int i=index;i<=n;i++)
        {
            v.push_back(i);   //pick the number
            find(n,k-1,i+1,v);
            v.pop_back(); //not pick the number
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        find(n,k,1,v);
        return res;
        
    }
};
