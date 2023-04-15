// There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

// In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

// Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

 

// Example 1:


// Input: piles = [[1,100,3],[7,8,9]], k = 2
// Output: 101
// Explanation:
// The above diagram shows the different ways we can choose k coins.
// The maximum total we can obtain is 101.
// Example 2:

// Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
// Output: 706
// Explanation:
// The maximum total can be obtained if we choose all coins from the last pile.
 

// Constraints:

// n == piles.length
// 1 <= n <= 1000
// 1 <= piles[i][j] <= 105
// 1 <= k <= sum(piles[i].length) <= 2000




// class Solution {
// public:
// int solve(vector<vector<int>>&p,int k,int i,vector<vector<int>>&dp)
// {
//     if(i>=p.size())return 0;
//     if(dp[i][k]!=-1)return dp[i][k];
//     int maxi=0;
//     maxi=max(maxi,solve(p,k,i+1,dp));
//     for(int j=0;j<p[i].size();j++)
//     {
//         if(j+1<=k)
//         {
//             maxi=max(maxi,p[i][j]+solve(p,k-j-1,i+1,dp));
//         }
//         else break;
//     }
//     return dp[i][k]=maxi;
// }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
//         for(int i=0;i<piles.size();i++)
//         {
//             for(int j=1;j<piles[i].size();j++)
//             {
//                 piles[i][j]+=piles[i][j-1];
//             }
//         }
//          int n=piles.size();
//         vector<vector<int>>dp(n+3,vector<int>(k+3,-1));
       
//         for(int i=0;i<piles.size()+1;i++)
//         {
//             for(int j=0;j<=k;j++)
//             {
//                 piles[i][j]=-1;
//             }
//         }
//         return solve(piles,k,0,dp);
//     }
// };




class Solution {
public:
    //startPileIdx is always 0
    //piles under consideration for each call ==> [pileIdx = 0 to pileIdx = endPileIdx]
    int solve(vector<vector<int>>&piles, vector<vector<int>>&dp, int endPileIdx, int k)
    {
        if (endPileIdx < 0 || k == 0) return 0;
        if (dp[endPileIdx][k] != -1) return dp[endPileIdx][k];
        
        int currPileSize = piles[endPileIdx].size(); 
        int maxCanPick = min(k, currPileSize);
        
        //consider 'not picking' any coin
        int maxSum = solve(piles, dp, endPileIdx - 1, k);  //DON'T PICK ANY COIN FROM CURR PILE
        int pickedSum = 0;
        //===============================================================================
        //now consider picking some coins
        for (int i = 0; i < maxCanPick; i++)
        {
            int coinValue = piles[endPileIdx][i];
            pickedSum += coinValue;
            
            int nextMaxSum = solve(piles, dp, endPileIdx - 1, k - i - 1); 
            maxSum = max(maxSum, pickedSum + nextMaxSum);
        }
        //=================================================================================
        return dp[endPileIdx][k] = maxSum;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        int ans = solve(piles, dp, n - 1, k);
        return ans;
    }
};
