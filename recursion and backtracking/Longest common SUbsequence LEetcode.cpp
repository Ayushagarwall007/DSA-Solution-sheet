// 1143. Longest Common Subsequence
// Medium

// 8285

// 96

// Add to List

// Share
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
    int solve(string a,string b , int i, int j)
    {
        if(i>a.size()-1) return 0;
        if(j==b.size()) return 0;
        
        int ans=0;
        // abb match karenge dono string ke characters koo or agar same aayenge to i++ or j++ ki call lenge
        if(a[i]==b[j])
            ans=1+solve(a,b,i+1,j+1);
        else
         // agar match nahi kaarta hai to yaa to hum a kaa nahi lake b kaa baaki kaa check kaarenge yaa b kaa nahi leke a kaa baaki kaa check kaarenge or jo dono calls mai max aayegaa usko include kaarebge ans mai
        {
            ans=max(solve(a,b,i,j+1) , solve(a,b,i+1,j) );
        }
        return ans;
        
    }
    int longestCommonSubsequence(string text1, string text2) {
       int i=0;
        int j=0;
         return 
             solve(text1,text2,i,j);
        
    }
};
