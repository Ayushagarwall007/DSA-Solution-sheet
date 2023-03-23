// There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

// You will pick any pizza slice.
// Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
// Your friend Bob will pick the next slice in the clockwise direction of your pick.
// Repeat until there are no more slices of pizzas.
// Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

// Example 1:


// Input: slices = [1,2,3,4,5,6]
// Output: 10
// Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
// Example 2:


// Input: slices = [8,9,8,6,1,1]
// Output: 16
// Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
 

// Constraints:

// 3 * n == slices.length
// 1 <= slices.length <= 500
// 1 <= slices[i] <= 1000



// class Solution {
// public:
// int solve(int curr,int end,vector<int>&slices,int n)
// {
//     if(curr>end or n==0)return 0;
//     int take=slices[curr]+solve(curr+2,end,slices,n-1);
//     int notTake=0+solve(curr+1,end,slices,n);
//     return max(take,notTake);
// }
//     int maxSizeSlices(vector<int>& slices) {
//         int k=slices.size();
//          int case1=solve(0,k-2,slices,k/3);
//          int case2=solve(1,k-1,slices,k/3);
//          return max(case1,case2);

//     }
// };

// using the concept that we use in hosuse robber agar hum 1st element lere hai to last nahi lenge or agar last lere hai too first nahi lenge orr phir using the principle of take and not take approach we find the maximum of two and finally return the ans,

class Solution {
public:
int solve(int curr,int end,vector<int>&slices,int n,vector<vector<int>>&dp)
{
    if(curr>end or n==0)return 0;
    if(dp[curr][n]!=-1)return dp[curr][n];
    int take=slices[curr]+solve(curr+2,end,slices,n-1,dp);
    int notTake=0+solve(curr+1,end,slices,n,dp);
    return dp[curr][n]=max(take,notTake);
}
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>>dp1(k,vector<int>(k,-1));
         int case1=solve(0,k-2,slices,k/3,dp1);
         vector<vector<int>>dp2(k,vector<int>(k,-1));
         int case2=solve(1,k-1,slices,k/3,dp2);
         return max(case1,case2);

    }
};






