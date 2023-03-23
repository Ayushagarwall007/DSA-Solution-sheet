// You have n dice, and each die has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 1, k = 6, target = 3
// Output: 1
// Explanation: You throw one die with 6 faces.
// There is only one way to get a sum of 3.
// Example 2:

// Input: n = 2, k = 6, target = 7
// Output: 6
// Explanation: You throw two dice, each with 6 faces.
// There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
// Example 3:

// Input: n = 30, k = 30, target = 500
// Output: 222616187
// Explanation: The answer must be returned modulo 109 + 7.
 

// Constraints:

// 1 <= n, k <= 30
// 1 <= target <= 1000



// class Solution {
// public:
// 	int f(int i,int tar,int k,int n){
// 		if(i==n){
// 			if(!tar) return 1;
// 			return 0;
// 		}    
// 		int p=0;
// 		for(int j=1;j<=k;j++){
// 			if(tar>=j) p+=f(i+1,tar-j,k,n);
// 		}
// 		return p;
// 	}

// 	int numRollsToTarget(int n, int k, int tar) {
// 		return f(0,tar,k,n);
// 	}
// };



class Solution {
public:
	int mod=1e9+7;
	int f(int i,int tar,int k,int n,vector<vector<int>>& dp){
		if(i==n){
			if(!tar) return 1;
			return 0;
		}    
		if(dp[i][tar]!=-1) return dp[i][tar];
		long long p=0;
		for(int j=1;j<=k;j++){
			if(tar>=j) p+=f(i+1,tar-j,k,n,dp)%mod;
		}
		return dp[i][tar]=p%mod;
	}

	int numRollsToTarget(int n, int k, int tar) {
		vector<vector<int>> dp(n,vector<int>(tar+1,-1));
		return f(0,tar,k,n,dp)%mod;
	}
};



// class Solution {
// public:
// 	int mod=1e9+7;
// 	int numRollsToTarget(int n, int k, int tar) {
// 		vector<vector<int>> dp(n+1,vector<int>(tar+1,0));
// 		dp[n][0]=1;
// 		for(int i=n-1;i>=0;i--){
// 			for(int t=0;t<=tar;t++){
// 				long long p=0;
// 				for(int j=1;j<=k;j++){
// 					if(t>=j) p+=dp[i+1][t-j]%mod;
// 				}
// 				dp[i][t]=p%mod;
// 			}
// 		}
// 		return dp[0][tar];
// 	}
// };

