// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.


class Solution {
public:
    
    int solve(string s,int left,int right)
    {
        int ans=0;
        while(left>=0 && right <s.length() && s[right]==s[left])
        {
            ans++;
            left--;
            right ++;
        }
        return ans;
    }
    int countSubstrings(string s) 
    {
        int ans=0;
        for (int i=0;i<s.size();i++)
        {
            ans+=solve(s,i,i); // for odd length substring 
            ans+=solve(s,i,i+1);// for even length sunstring 
        }
        return ans;
    }
};

// A simple approcah for this problem would be to traverse the complete string and consider each character as the center of a palindrome and then start 
// traversing out toward the terminal points of string and if character are same at right and left then count it as palindrome.

// first we have to count odd size palindrom, and then we have to count even size palindrome.
