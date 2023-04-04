// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

// Constraints:

// 1 <= prices.length <= 3 * 104
// // 0 <= prices[i] <= 104



class Solution {
public:
int solveMem(int ind,int n,int canBuy,vector<int>&prices,vector<vector<int>>&dp)
{
    if(ind>=n)return 0;
    int profit=0;
    if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
    if(canBuy)
    {
        int buynow=-prices[ind]+solveMem(ind+1,n,0,prices,dp);
        int skipKaro=solveMem(ind+1,n,1,prices,dp);
        profit=max(buynow,skipKaro);
    }
    else // abb yaa to sell kaar  sakte hai yaa ignore
    {
        int sellnow=prices[ind]+solveMem(ind+1,n,1,prices,dp);
        int skipKaro=solveMem(ind+1,n,0,prices,dp);
        profit=max(sellnow,skipKaro);
    }
    return dp[ind][canBuy]=profit;

}


// int solveTab(vector<int>prices)
// {
//     int n=prices.size();
//     vector<vector<int>>dp(n+1,vector<int>(2,-1));
//     for(int i=prices.size()-1;i>=0;i--)
//     {
//         for(int canBuy=0;canBuy<=1;canBuy++)
//         {
//             int profit=0;
//     if(canBuy)
//     {
//         int buynow=-prices[i]+dp[i+1][0];
//         int skipKaro=dp[i+1][1];
//         profit=max(buynow,skipKaro);
//     }
//     else // abb yaa to sell kaar  sakte hai yaa ignore
//     {
//         int sellnow=prices[i]+dp[i+1][1];
//         int skipKaro=dp[i+1][0];
//         profit=max(sellnow,skipKaro);
//     }
//     dp[i][canBuy]=profit;
//         }
//     }
//     return dp[0][1];
        
    
// }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int canBuy=1;
        int profit=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
         return solveMem(0,n,canBuy,prices,dp);
        // return solveTab(prices);
         
    }
};

// LETS take a counter variable buy ie when 0 you can not buy the stock in this condition either you have to sell the stock or ignore it or when 1 you are either able to buy the stock or ignore it.
// in both the condition you have to find the maximum profit;


// now while buying the stock we will add the index value with the - sign in the profit  and while you sell the stock you have to add the index with the +sign  to the pro0fit .
// at last return the profit.
