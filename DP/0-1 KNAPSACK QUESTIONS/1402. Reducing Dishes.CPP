// 1402. Reducing Dishes
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

// Example 1:

// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
// Example 2:

// Input: satisfaction = [4,3,2]
// Output: 20
// Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
// Example 3:

// Input: satisfaction = [-1,-4,-5]
// Output: 0
// Explanation: People do not like the dishes. No dish is prepared.
 

// Constraints:

// n == satisfaction.length
// 1 <= n <= 500
// -1000 <= satisfaction[i] <= 1000





// class Solution {
// public:
// 	int f(int i,int count,vector<int>& sat,int n){
// 		if(i==n) return 0;
// 		int pick=count*sat[i]+f(i+1,count+1,sat,n);
// 		int notpick=f(i+1,count,sat,n);
// 		return max(pick,notpick);
// 	}

// 	int maxSatisfaction(vector<int>& sat) {
// 		int n=sat.size();
// 		sort(sat.begin(),sat.end());
// 		return f(0,1,sat,n);
// 	}
// };

// top down approach

class Solution {
	public:
		int f(int i,int count,vector<int>& sat,int n,vector<vector<int>>& dp){
			if(i==n) return 0;
			if(dp[i][count]!=-1) return dp[i][count];
			int pick=count*sat[i]+f(i+1,count+1,sat,n,dp);
			int notpick=f(i+1,count,sat,n,dp);
			return dp[i][count]=max(pick,notpick);
		}

		int maxSatisfaction(vector<int>& sat) {
			int n=sat.size();
			sort(sat.begin(),sat.end());
			vector<vector<int>> dp(n,vector<int>(n+1,-1));
			return f(0,1,sat,n,dp);
		}
	};
	

// // bottum up approach 

//     class Solution {
// public:
// 	int maxSatisfaction(vector<int>& sat) {
// 		int n=sat.size();
// 		sort(sat.begin(),sat.end());
// 		vector<vector<int>> dp(n+1,vector<int>(n+2,0));
// 		for(int i=n-1;i>=0;i--){
// 			for(int count=n;count>=1;count--){
// 				int pick=count*sat[i]+dp[i+1][count+1];
// 				int notpick=dp[i+1][count];
// 				dp[i][count]=max(pick,notpick);
// 			}
// 		}
// 		return dp[0][1];
// 	}
// };
