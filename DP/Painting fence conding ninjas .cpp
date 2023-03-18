// PROBLEM STATEMENT
// Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

// Ninja wonders how many ways are there to do the above task, so he asked for your help.

// Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

// Example:
// Input: 'N' = 3, 'K' = 2
// Output: 6

// Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

// 110
// 001
// 101
// 100
// 010
// 011
// Input Format :
// The first line of input contains an integer 'T', denoting the number of test cases. 

// Each test case will contain two integers 'N' and 'K' denoting the number of posts on the fence and the number of colors Ninja has.
// Output Format :
// For each test case, print the number of ways modulo 10^9 + 7 to paint the fence.

// Output for each test case will be printed in a separate line.
// Note :
// You don't need to print anything. It has already been taken care of. Just implement the given function.
// Constraints :
// 1 <= ‘T’ <= 10
// 1 <= 'N' <= 10^5
// 1 <= 'K' <= 10^5
// Time Limit: 1 sec






// in this let assume for n=2 we have 2 choices
// choice 1 : jaab dono colors same hoo no of ways =k
// choice 2 :when the colors are different no of ways k*(n-1)
// total ways for n=2 k+(k*(n-1))

// now for n=3
// choice 1 aab saab ke aage same colors lagaa denge  no of ways = 6 jo n=2 ke choice 2 ke aage coolors laagate hai
// choice 2 aab jaab saab last ke colors different hotte hai too no 
// total recursive solutoin 
// solve(n) = solve(n - 1) * (k - 1)/*different color ke liye*/ - solve(n - 2) * (k - 1) // same coloor ke liye for last two blocks with same colors


#include <bits/stdc++.h> 
#define MOD 1000000007
//Recursion
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}


int solve(int n, int k){
    //base case
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));


    int ans = add(mul(solve(n-2,k),k-1), mul(solve(n-1,k),k-1));
    return ans;
}


//Recursion Method-2
int solve(int n, int k){
    if(n==1) return k;
    if(n==2){
        return (k%MOD + (k*(k-1))%MOD)%MOD;
    }


    int ans = ((solve(n-2,k)*(k-1))%MOD + (solve(n-1, k)*(k-1))%MOD)%MOD;
    return ans;
}


//MEMORIZATION
int solveMem(int n, int k,vector<int> &dp){
    //base case
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));


    if(dp[n] != -1) return dp[n];


    dp[n] = add(mul(solveMem(n-2,k,dp),k-1), mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}


//Tabulation
int solveTab(int n, int k){
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));


    for(int i=3; i<n+1; i++){
        dp[i] =add(mul(dp[i-2],k-1), mul(dp[i-1],k-1));
    }
    return dp[n];
}


//Space Optimization
int solveSpaceOptimization(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k,k-1));


    for(int i=3; i<n+1; i++){
        int ans =add(mul(prev2,k-1), mul(prev1,k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int numberOfWays(int n, int k) {
    // Recursion
    // return solve(n,k);


    Memorization
    vector<int> dp(n+1,-1);
    return solveMem(n,k,dp);



    // Tabulation
    // return solveTab(n, k);




}
