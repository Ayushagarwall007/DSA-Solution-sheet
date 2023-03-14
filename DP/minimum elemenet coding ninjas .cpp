// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0



#include <bits/stdc++.h> 
// int solveRec(vector<int>nums,int target)
// {
//     if(target==0)return 0;
//     if(target<0)return INT_MAX;
//     int mini=INT_MAX;
//     for(int i=0;i<nums.size();i++)
//     {
//         int ans=solveRec(nums,target-nums[i]);
//         if(ans!=INT_MAX)
//         {
//             mini=min(1+ans,mini);
//         }
//     } 
//     return mini;

// }
// int solveMem(vector<int>nums,int target,vector<int>&dp)
// {
//     if(target==0)return 0;
//     if(target<0)return INT_MAX;
//     if(dp[target]!=-1)return dp[target];
//     int mini=INT_MAX;
//     for(int i=0;i<nums.size();i++)
//     {
//         int ans=solveMem(nums,target-nums[i],dp);
//         if(ans!=INT_MAX)
//         {
//             mini=min(1+ans,mini);
//         }
//     } 
//     return dp[target]=mini;

// }

int solveTab(vector<int>&nums,int target)
{
    vector<int>dp(target+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=target;i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if(i-nums[j]>=0 and dp[i-nums[j]]!=INT_MAX)
            dp[i]=min(dp[i],1+dp[i-nums[j]]);
        }
    }
    return dp[target];

}
int minimumElements(vector<int> &num, int x)
{
    // int ans=solveRec(num,x);
    // return ans!=INT_MAX?ans:-1;
    // vector<int>dp(x+1,-1);
    // int ans=solveMem(num,x,dp);
    // return ans!=INT_MAX?ans:-1;

    int ans=solveTab(num,x);
    return ans!=INT_MAX?ans:-1;

}
