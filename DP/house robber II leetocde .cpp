// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000


class Solution {
public:
int solve(vector<int>&nums,int i,vector<int>&dp)
{
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int inc=nums[i]+solve(nums,i+2,dp);
    int exc=solve(nums,i+1,dp);
    return dp[i]=max(inc,exc);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        //isme agar humm first elemet lere hai to last element ko nahi lena or aagar last elemeent lere hai to first elewment ko nahi lena hai..ussi ke hissab se hum parent array ko 2 allag aalag array mai divide kaar denge....
        vector<int>firstInc,lastInc;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)firstInc.push_back(nums[i]);
            if(i!=0)lastInc.push_back(nums[i]);
        }
        vector<int>dp1(firstInc.size(),-1),dp2(lastInc.size(),-1);
        return max(solve(firstInc,0,dp1),solve(lastInc,0,dp2));
    }
};
