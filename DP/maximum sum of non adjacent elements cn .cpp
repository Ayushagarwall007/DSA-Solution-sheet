// PROBLEM STATEMENT
// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

// Note:
// A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
// Input Format:
// The first line contains a single integer ‘T’ denoting the number of test cases.

// The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

// The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
// Output Format:
// For each test case, print a single integer that denotes the maximum sum of the non-adjacent elements.

// Print the output of each test case in a separate line.
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 500
// 1 <= N <= 1000
// 0 <= ARR[i] <= 10^5

// Where 'ARR[i]' denotes the 'i-th' element in the array/list.

// Time Limit: 1 sec.

#include <bits/stdc++.h> 
int solve(vector<int>&nums,int n)
{
    vector<int>dp(n,0);
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return solve1(nums,n);
}


#include <bits/stdc++.h> 
#include<vector>
using namespace std;
int solve(vector<int>&nums,int index,vector<int>&dp)
{
    if(index>=nums.size())return 0;
    if(dp[index]!=-1)return dp[index];
    int inc=solve(nums,index+2,dp)+nums[index];
    int exc=solve(nums,index+1,dp)+0;

    dp[index]=max(inc,exc);
    return dp[index];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // int ans=0;
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return solve(nums,0,dp);    
}
