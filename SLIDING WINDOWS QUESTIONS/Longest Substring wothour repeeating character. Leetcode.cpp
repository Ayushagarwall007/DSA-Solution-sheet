// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(s==" ") return 1;
        if(n==0) return 0;
        if(n==1)return 1;

        int c=0 ,res=0;
        for(int i=0;i<n;i++)
        {
            int cn=1;
            for(int j=c;j<i;j++)
            {
                if(s[i]==s[j])
                {
                    c=j+1;
                    break;
                }
                cn+=1;
            }
            res=max(res,cn);
        }
        return res;
    }
};
