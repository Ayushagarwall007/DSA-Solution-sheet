// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?



// class Solution {
// public:
// int solve(vector<int>&nums , int curr, int prev,vector<vector<int>>&dp)
// {
//     if(curr>=nums.size())return 0;
//     if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
//     int take=0;
//     if(prev==-1 or nums[curr]>nums[prev])
//     {
//         take=1+solve(nums,curr+1,curr,dp);
//     }
//     int notTake=0+solve(nums,curr+1,prev,dp);

//     int ans=max(take,notTake);
//     return dp[curr][prev+1]=ans;
// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         int ans=solve(nums,0,-1,dp);
//         return ans;
//     }
// }; 



class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int len=0+dp[ind+1][prev+1];

                if(prev==-1 || nums[ind]>nums[prev])
                len=max(len,1+dp[ind+1][ind+1]);

                dp[ind][prev+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};
