// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.
// Accepted
// 323.4K
// Submissions
// 530.5K
// Acceptance Rate
// 61.0%



class Solution {
public:
int solve(string s1,string s2)
{
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for(int i=s1.length()-1;i>=0;i--)
    {
        for(int j=s2.length()-1;j>=0;j--)
        {
            int ans=0;
            if(s1[i]==s2[j]) ans=1+dp[i+1][j+1];
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
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        return solve(s1,s);

    }
};
