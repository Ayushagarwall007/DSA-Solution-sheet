// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100



// iss question mai humee total sum ko 2 equal part mai divivde kaarna hai to uska matlaab hai ki agar humme aisa kaarna hai to humme given array kaa total sum even chaiye tabhi hum usko equal part ke 2 mai divide kaar sakte hai ....
// agar total sum odd hua to partition possible nahi hai ...
// phir humm subset sum approACH lagani hai for sum = total_sum/2 ke liye

class Solution {
public:
// bool solveMem(vector<int>&nums,int i,int n,int target,vector<vector<int>>&dp)
// {
//     if(target<0)return 0;
//     if(i>=n)return 0;
//     if(target==0)return 1;
//     if(dp[i][target]!=-1)return dp[i][target];
//     bool inc=solve(nums,i+1,n,target-nums[i],dp);
//     bool exc=solve(nums,i+1,n,target-0,dp);
    

//     return dp[i][target]=inc or exc;
// }

bool solveTab(vector<int>&nums,int n,int target)
{
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=target;j++)
        {
            bool inc=0;
            if(j-nums[i]>=0)
            inc=dp[i+1][j-nums[i]];
            bool exc=dp[i+1][j];
            dp[i][j]=inc or exc;
        }
        
        
    }
    return dp[0][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        if(sum&1)return 0;
        else 
        // return solveMem(nums,0,n,target,dp);
        return solveTab(nums,n,target);
    }
};

