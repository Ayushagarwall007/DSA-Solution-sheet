// 44. Wildcard Matching
// Hard
// 6.1K
// 260
// Companies
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.


class Solution {
public:

    bool solve(string a,string b,int i,int j)
    {
        if(i==0 and j==0 ) return true;
        if(i>0 and j==0) return false;
        if(i==0 and j>0) 
        {
            for(int k=j-1;k>=0;k--)
            {
                if(k!='*')return false;
            }
            return true;
        }

        if(a[i-1]==b[j-1] or b[j-1]=='?') return solve(a,b,i-1,j-1);

        else if(b[j-1]=='*')
        {
           return solve(a,b,i,j-1) or solve(a,b,i-1,j);
        }
        else{
        return false;
        }
    }
    bool isMatch(string s, string p) {
       return solve(s,p,s.size(),p.size());
    }
};
