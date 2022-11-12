// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []
 

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.



class Solution {
public:
void  solve(int index,string s,set<string>st,vector<string>&result,string temp)
{
    if(index==s.length()) 
    {
        temp.pop_back();
        result.push_back(temp);
        return;
    }

    string substr="";
    for(int i=index;i<s.length();i++)
    {
        substr.push_back(s[i]);
        // cout<<substr<<" ";
        if(st.find(substr)!=st.end())
        {
            solve(i+1,s,st,result,temp+substr+" ");
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<string> result;

        for(auto str:wordDict)
        {
            st.insert(str);
        }
        string temp="";
        solve(0,s,st,result,temp);
        return result;
    }
}; 
