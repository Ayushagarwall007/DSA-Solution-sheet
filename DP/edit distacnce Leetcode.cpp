// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.


class Solution {
public:
    int solve(string word1,string word2 ,int i,int j)
    {
        if(i==word1.size())
        return word2.size()-j;

        if(j== word2.size()) return word1.size()-i;

        if(word1[i]==word2[j]) return solve(word1,word2,i+1,j+1);
        else
        {
            int insertAns=solve(word1,word2,i,j+1);
            int replaceAns=solve(word1,word2,i+1,j+1);
            int DeleteAns=solve(word1,word2,i+1,j);

            return min(insertAns,min(replaceAns,DeleteAns))+1;
        }
    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }


    // Tabulation - TC: O(n * m), SC: O(n * m)
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // We make dp array 1 indexed
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else
// Delete - dp[i-1][j], Insert - dp[i][j-1], Replace - dp[i-1][j-1]
                    dp[i][j] = 1 + min(dp[i-1][j], 
        min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};
