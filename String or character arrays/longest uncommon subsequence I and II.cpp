// 522. Longest Uncommon Subsequence II
// Medium
// 437
// 1.2K
// Companies
// Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

// An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

// A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

// For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
 

// Example 1:

// Input: strs = ["aba","cdc","eae"]
// Output: 3
// Example 2:

// Input: strs = ["aaa","aaa","aa"]
// Output: -1
 

// Constraints:

// 2 <= strs.length <= 50
// 1 <= strs[i].length <= 10
// strs[i] consists of lowercase English letters.













class Solution {
public:
bool isSubsequence(string a,string b)
{
    int n=a.length();
    int m=b.length();
    int i=0;
    int j=0;
    while(i<n and j<m)
    {
        if(a[i]==b[j])i++;
        j++;
    }
    return i==n;
}
    int findLUSlength(vector<string>& strs) {
        int n=strs.size();
        int maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && isSubsequence(strs[i],strs[j]))
                {
                    flag=1;
                    break;
                }
            }
                if(flag==0)
                {
                    int x=strs[i].size();
                    maxx=max(x,maxx);
                }
            
        }
        if(maxx==INT_MIN)return -1;
        return maxx;
    }
};






// 521. Longest Uncommon Subsequence I
// Easy
// 710
// 6.1K
// Companies
// Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If the longest uncommon subsequence does not exist, return -1.

// An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.

// A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

// For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
 

// Example 1:

// Input: a = "aba", b = "cdc"
// Output: 3
// Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
// Note that "cdc" is also a longest uncommon subsequence.
// Example 2:

// Input: a = "aaa", b = "bbb"
// Output: 3
// Explanation: The longest uncommon subsequences are "aaa" and "bbb".
// Example 3:

// Input: a = "aaa", b = "aaa"
// Output: -1
// Explanation: Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a.
 

// Constraints:

// 1 <= a.length, b.length <= 100
// a and b consist of lower-case English letters.


class Solution {
public:
     int findLUSlength(string a, string b) {
        
        if(a == b) return -1;
        
        int x = a.length();
        int y = b.length();
        return (x>y ) ? x : y ; 
    }
};











