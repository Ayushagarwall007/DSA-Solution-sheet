// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000



class Solution {
public:
int solveMem(int ind,int n,int canBuy,vector<int>&prices,int limit , vector<vector<vector<int> > > &dp)
{
    if(ind>=n)return 0;
    if(limit==0)return 0;
    if(dp[ind][canBuy][limit]!=-1)return dp[ind][canBuy][limit];
    int profit=0;

    // if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
    if(canBuy)
    {
        int buynow=-prices[ind]+solveMem(ind+1,n,0,prices,limit,dp);
        int skipKaro=solveMem(ind+1,n,1,prices,limit,dp);
        profit=max(buynow,skipKaro);
    }
    else // abb yaa to sell kaar  sakte hai yaa ignore
    {
        int sellnow=prices[ind]+solveMem(ind+1,n,1,prices,limit-1,dp);
        int skipKaro=solveMem(ind+1,n,0,prices,limit,dp);
        profit=max(sellnow,skipKaro);
    }
    // return dp[ind][canBuy]=profit;
    return dp[ind][canBuy][limit]= profit;

}
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveMem(0,prices.size(),1,prices,k,dp);
    }
};
