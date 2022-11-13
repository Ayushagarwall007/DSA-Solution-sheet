// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

// Return all the possible results. You may return the answer in any order.

 

// Example 1:

// Input: s = "()())()"
// Output: ["(())()","()()()"]
// Example 2:

// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]
// Example 3:

// Input: s = ")("
// Output: [""]
 

// Constraints:

// 1 <= s.length <= 25
// s consists of lowercase English letters and parentheses '(' and ')'.
// There will be at most 20 parentheses in s.



class Solution {
public:
int getRemovalCount(string s)// this function is used to find the number of removals of the string s
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch=='(') st.push(ch);
        else if(ch==')')
        {
            if(!st.empty() and st.top()=='(') st.pop();
            else
            {
                st.push(ch);
            }
        }
    }
    return st.size();
}

void solve(string s,int removeCnt,vector<string>&ans,map<string,bool>&mp)
{
    if(mp[s]==true)return;
    else mp[s]=true;
    if(removeCnt==0)
    {
        int numRemoval=getRemovalCount(s);
        if(numRemoval==0) ans.push_back(s);
        return;
    }

    // aab hurr ek index ko remove kaarke check kaarenge ki string valid hai ki nahi

    for(int i=0;i<s.size();i++)
    {
        string leftStr=s.substr(0,i);
        string rightStr=s.substr(i+1);
        // isme humm uss particular index ko haata ke baaki ki string check kaar rahe hai or unko join kaar denge
        string temp=leftStr+rightStr;
        solve(temp,removeCnt-1,ans,mp); 

    }
}
    vector<string> removeInvalidParentheses(string s) {
        int removeCnt=getRemovalCount(s); 
        map<string,bool>mp;
        vector<string> ans;
        solve(s,removeCnt,ans,mp);
        return ans;
    }
};
