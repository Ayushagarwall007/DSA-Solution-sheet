// 45. Jump Game II
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].



class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),i=0,ans=0;
        for(int i=1;i<n;i++)
        {
            nums[i]=max(nums[i]+i,nums[i-1]);
        }
        while(i<n-1)
        {
            ans++;
            i=nums[i];
        }
        return ans;
    }
};



// class Solution {
// public:
// int solve(int ind,int n, vector<int>&nums,vector<int>&dp)
// {
//     if(ind>=n-1)return 0;
//     if(dp[ind]!=-1)return dp[ind];
//     int mini=1e5;
//     for(int i=1;i<=nums[ind];i++)
//     {
//         mini=min(mini,1+solve(ind+i,n,nums,dp));
//     }
//     return dp[ind]=mini;
// }
//     int jump(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)return 0;
//         vector<int>dp(n,-1);
//         return solve(0,n,nums,dp);
//     }
// };
