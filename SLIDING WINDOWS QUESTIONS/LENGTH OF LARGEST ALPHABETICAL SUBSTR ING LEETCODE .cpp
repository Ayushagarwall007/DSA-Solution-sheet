// 2414. Length of the Longest Alphabetical Continuous Substring
// Medium
// 345
// 22
// Companies
// An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

// For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
// Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.

 

// Example 1:

// Input: s = "abacaba"
// Output: 2
// Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
// "ab" is the longest continuous substring.
// Example 2:

// Input: s = "abcde"
// Output: 5
// Explanation: "abcde" is the longest continuous substring.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only English lowercase letters.




class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size())
        {
            if(s[j]+1==s[j+1])
            {
                j++;
            }
            else
            {
                j++;
                i=j;

            }
            ans=max(ans,(j-i+1));
        }
        return ans;
    }
};