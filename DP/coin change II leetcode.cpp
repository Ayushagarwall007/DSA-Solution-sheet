// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

 

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1
 

// Constraints:

// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000




// class Solution {
// public:
// int solve(int n,int t,vector<int>&coin)
// {
//     if(n==0)return (t%coin[0]==0);
//     int notTake=solve(n-1,t,coin);
//     int take=0;
//     if(coin[n]<=t)take=solve(n,t-coin[n],coin);
//     return (take+notTake);
// }
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         return solve(n-1,amount,coins);
//     }
// };


// ->MEMOIZATION 

// TC=O(N*TARGET)
// SC=O(N*TARGET)+O(TARGET)

class Solution {
public:
    int ff(int n,int t,vector<int>&coin,vector<vector<int>>&dp)
    {
        if(n==0)
            return(t%coin[0]==0);

        if(dp[n][t]!=-1) return dp[n][t];
        int nottake=ff(n-1,t,coin,dp);
        int take=0;
        if(coin[n]<=t) take=ff(n,t-coin[n],coin,dp);
        return dp[n][t]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return ff(n-1,amount,coins,dp);
    }
};


// ->TABULATION

// TC=O(N*TARGET)
// SC=O(N*TARGET)

// class Solution {
// public:
//         int change(int amount, vector<int>& coins)
//         {
//             int n=coins.size();
//             vector<vector<int>>dp(n,vector<int>(amount+1,0));
//             for(int t=0;t<=amount;t++)
//             {
//                 dp[0][t]=(t%coins[0]==0); 
//             }
//             for(int ind=1;ind<n;ind++)
//             {
//                 for(int t=0;t<=amount;t++)
//                 {
//                     int nottake=dp[ind-1][t];
//                     int take=0;
//                     if(coins[ind]<=t) take= dp[ind][t-coins[ind]];
//                     dp[ind][t]=take+nottake;
//                 }
//             }
//             return dp[n-1][amount];
//         }
// };
