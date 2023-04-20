// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: words = ["acca","bbbb","caca"], target = "aba"
// Output: 6
// Explanation: There are 6 ways to form target.
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
// Example 2:

// Input: words = ["abba","baab"], target = "bab"
// Output: 4
// Explanation: There are 4 ways to form target.
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
// "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
// "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// All strings in words have the same length.
// 1 <= target.length <= 1000
// words[i] and target contain only lowercase English letters.




// class Solution {
// public:
//     long long MOD = 1000000007;
//     int solve(vector<vector<int>>&freq, string& target, vector<vector<int>>& dp, int colIdx, int targetIdx)
//     {
//         //if target is complete, then irrespective of colIdx the formation is 'VALID'
//         if (targetIdx == target.size()) return 1; 
//         if (colIdx == freq.size()) //will come here only when (targetIdx != target.size())
//             return 0;  //means target is not complete and still the string choices are over
//                        //so 'INVALID'

//         if (dp[colIdx][targetIdx] != -1) return dp[colIdx][targetIdx];
//         char targetCh = target[targetIdx];
//         int notPickWays = solve(freq, target, dp, colIdx + 1, targetIdx);
//         //===================================================================
//         int pickWays = 0;
//         if (freq[colIdx][targetCh - 'a'] != 0)
//         {
//             int currWays = freq[colIdx][targetCh - 'a'];
//             int nextWays = solve(freq, target, dp, colIdx + 1, targetIdx + 1);
//             pickWays = (currWays * (long long)nextWays) % MOD;
//         }
//         //====================================================================
//         return dp[colIdx][targetIdx] = ((pickWays + (long long)notPickWays) % MOD);
        
//     }
//     int numWays(vector<string>& words, string target) 
//     {
//         int m = words.size(), n = words[0].size();
//         vector<vector<int>>freq(n, vector<int>(26, 0));
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 char ch = words[i][j];
//                 freq[j][ch - 'a']++; //freq of 'ch' in jth col
//             }
//         }
//         vector<vector<int>>dp(n, vector<int>(target.size(), -1));
//         int ans = solve(freq, target, dp, 0, 0);
//         return ans;
//     }
// };



class Solution {
public:
    long long MOD = 1000000007;
    int solve(vector<vector<int>>&freq, string& target, vector<vector<int>>& dp, int colIdx, int targetIdx)
    {
        //if target is complete, then irrespective of colIdx the formation is 'VALID'
        if (targetIdx == target.size()) return 1; 
        if (colIdx == freq.size()) //will come here only when (targetIdx != target.size())
            return 0;  //means target is not complete and still the string choices are over
                       //so 'INVALID'

        if (dp[colIdx][targetIdx] != -1) return dp[colIdx][targetIdx];
        char targetCh = target[targetIdx];
        int notPickWays = solve(freq, target, dp, colIdx + 1, targetIdx);
        //===================================================================
        int pickWays = 0;
        if (freq[colIdx][targetCh - 'a'] != 0)
        {
            int currWays = freq[colIdx][targetCh - 'a'];
            int nextWays = solve(freq, target, dp, colIdx + 1, targetIdx + 1);
            pickWays = (currWays * (long long)nextWays) % MOD;
        }
        //====================================================================
        return dp[colIdx][targetIdx] = ((pickWays + (long long)notPickWays) % MOD);
        
    }
    int numWays(vector<string>& words, string target) 
    {
        int m = words.size(), n = words[0].size();
        vector<vector<int>>freq(n, vector<int>(26, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch = words[i][j];
                freq[j][ch - 'a']++; //freq of 'ch' in jth col
            }
        }
        vector<vector<int>>dp(n, vector<int>(target.size(), -1));
        int ans = solve(freq, target, dp, 0, 0);
        return ans;
    }
};
