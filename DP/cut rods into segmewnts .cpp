
/*
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next ‘T’ lines represent the ‘T’ test cases.

The only line of each test case contains 4 integers denoting ‘N’, ’X’, ’Y’, and ‘Z’,  where ‘N’ is the length of the rod and 'X', 'Y', 'Z' are the segments into which a given rod can be cut into. 
Output Format:
For each test case, return the maximum number of cut segments from the given rod.

Print the output of each test case in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraint:
1 <= T <= 50
1 <= N <= 10000
1 <= X, Y, Z <= N

Time Limit: 1 sec
*/
#include<bits/stdc++.h>
using namespace std;
int solveTab(int n,int x,int y ,int z)
{
	vector<int>dp(n+1,-1);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i-x>=0 and dp[i-x]!=-1)
		dp[i]=max(dp[i-x]+1,dp[i]);
		if(i-y>=0 and dp[i-y]!=-1)
		dp[i]=max(dp[i-y]+1,dp[i]);
		if(i-z>=0 and dp[i-z]!=-1)
		dp[i]=max(dp[i-z]+1,dp[i]);

	}
	if(dp[n]<0)return 0;
	else
	{return dp[n];}
	
}
// int solveMem(int n,int x,int y,int z,vector<int>&dp)
// {
// 	if(n==0)return 0;
// 	if(n<0)return INT_MIN;
// 	if(dp[n]!=-1)return dp[n];
// 	int first=solve(n-x,x,y,z,dp)+1;
// 	int second=solve(n-y,x,y,z,dp)+1;
// 	int third=solve(n-z,x,y,z,dp)+1;
// 	int ans=max(first,max(second,third));
// 	dp[n]=ans;

// 	return dp[n];
// }
int cutSegments(int n, int x, int y, int z) {
  // 	vector<int>dp(n+1,-1);
  // 	int ans=solveMem(n,x,y,z,dp);
  // 	return ans<0?0:ans;
  // }

  int ans = solveTab(n-1, x, y, z);
  return  ans;
}
