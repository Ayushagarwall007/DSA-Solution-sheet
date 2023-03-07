// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.




class Solution {
public:
int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp)
{
    if(i==text1.size())return 0;
    if(j==text2.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(text1[i]==text2[j])ans=solve(text1,text2,i+1,j+1,dp)+1;
    else
    {
        int opt1=solve(text1,text2,i+1,j,dp);
        int opt2=solve(text1,text2,i,j+1,dp);
        ans=max(opt1,opt2);
    }
    return dp[i][j]=ans;
}

int solve2(string &text1,string &text2)
{
     vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
     for(int i=text1.length()-1;i>=0;i--)
     {
         for(int j=text2.length()-1;j>=0;j--)
         {
             int ans=0;
             if(text1[i]==text2[j])ans=1+dp[i+1][j+1];
             else
             {
                 int opt1=dp[i+1][j];
                 int opt2=dp[i][j+1];
                 ans=max(opt1,opt2);
             }
             dp[i][j]=ans;
         }
         
     }
     return dp[0][0];
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        // return solve(text1,text2,0,0,dp);
        return solve2(text1,text2);
    }
};
