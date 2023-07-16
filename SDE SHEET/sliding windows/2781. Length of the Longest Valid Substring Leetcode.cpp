// You are given a string word and an array of strings forbidden.

// A string is called valid if none of its substrings are present in forbidden.

// Return the length of the longest valid substring of the string word.

// A substring is a contiguous sequence of characters in a string, possibly empty.

 

// Example 1:

// Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
// Output: 4
// Explanation: There are 9 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", and "aabc". The length of the longest valid substring is 4. 
// It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
// Example 2:

// Input: word = "leetcode", forbidden = ["de","le","e"]
// Output: 4
// Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
// It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
 

// Constraints:

// 1 <= word.length <= 105
// word consists only of lowercase English letters.
// 1 <= forbidden.length <= 105
// 1 <= forbidden[i].length <= 10
// forbidden[i] consists only of lowercase English letters.




class Solution {
public:
bool check(string &t,int j ,int r,set<string>&st)
{
    int n=t.size();
    int l=max(j,n-10);
    string x="";
    for(int i=n-1;i>=l;--i)
    {
        x.push_back(t[i]);
        string xx=x;
        reverse(xx.begin(),xx.end());
        if(st.find(xx)!=st.end())return 1;

    }
    return 0;
}
    int longestValidSubstring(string s, vector<string>& a) {
        set<string>st;
        int n=s.size();
        for(auto &e:a)
        {
            st.insert(e);
        }
        string t="";
        int j=0,ans=0;
        for(int i=0;i<n;i++)
        {
            t.push_back(s[i]);
            // cout<<t<<" ";
            while(check(t,j,i,st))
            j++;
             ans=max(i-j+1,ans);
        }
        return ans;
       
    }
    
};
