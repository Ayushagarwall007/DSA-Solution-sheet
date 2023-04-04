// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105




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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMem(0,prices.size(),1,prices,2,dp);
    }
};

// IN THIS QUESTION WE HAVE TO ADD ONE MORE VARIABLE IE LIMIT TO CHECK FOR AT MOST 2 TRNASACTIONS
//REST ALL CODE IS SAME AS BEST TIME TO BUY AND SELL STOCK II
