// Problem Statement
// Detailed explanation ( Input/output format, Notes, Constraints, Images )
// Sample Input 1:
// 2
// 5
// 2 5 7 8 10
// 8
// 3 5 8 9 10 17 17 20
// Sample Output 1:
// 12
// 24
// Explanation Of Sample Input 1:
// Test case 1:

// All possible partitions are:
// 1,1,1,1,1           max_cost=(2+2+2+2+2)=10
// 1,1,1,2             max_cost=(2+2+2+5)=11
// 1,1,3               max_cost=(2+2+7)=11
// 1,4                 max_cost=(2+8)=10
// 5                   max_cost=(10)=10
// 2,3                 max_cost=(5+7)=12
// 1,2,2               max _cost=(1+5+5)=12    

// Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.


// Test case 2:

// Possible partitions are:
// 1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
// 1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
// 1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
// and so on….

// If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 8 pieces, we get 8*3 = 24.
// Sample Input 2:
// 1
// 6
// 3 5 6 7 10 12
// Sample Output 2:
// 18






#include<bits/stdc++.h>
int fun(vector<int> &ar, int tar, vector<int>&dp){
   
   if(tar == 0)return 0;

   int take = 0;
   
   if(dp[tar] != -1)return dp[tar];
   for(int i = 1; i <= tar; i++){
       if(tar >= i){
		//    cout<<i-1<<" ";
           take = max(take, ar[i-1] + fun(ar, tar - i, dp));
		

       }
	   if(tar<i)break;
   }
   
   return dp[tar] = take;
}


int cutRod(vector<int> &price, int n)
{
// Write your code here.
   
    vector<int>dp(n+1, -1);
    return fun(price, n, dp);
}
