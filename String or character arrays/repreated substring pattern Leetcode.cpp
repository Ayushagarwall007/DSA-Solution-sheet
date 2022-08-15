// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

// Example 1:

// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
// Example 2:

// Input: s = "aba"
// Output: false
// Example 3:

// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.



class Solution {
public:
  bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;i--){                //commented below
            if(n%i==0){                                                             //i is expressing the size of the substring forming-->if length of the substring(i.e, i) divides n equally then we can say the substring can be/may be a possible solution,so we check further,else we skip.
                if(s.substr(0,n-i)==s.substr(i))return true;           //rotation approach-->if two substrings from first and last match then we can say they can repeatedly form the string.
            }
        }
        return false;
    
    }
};
