// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.length();
        if(s==" ")
            return 1;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int c=0;int res=0;
        for(int i=1;i<n;i++)
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
