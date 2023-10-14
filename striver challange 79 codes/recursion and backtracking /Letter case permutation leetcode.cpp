// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]
 

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.





class Solution {
public:
void solve(int i, string temp,string & s,vector<string>&ans)
{
    if(i>=s.size())
    {
        ans.push_back(temp);
        return;
    }
    if(s[i]>='0' and s[i]<='9')
    {
        temp+=s[i];
        solve(i+1,temp,s,ans);
    }
    else
    {
        temp+=toupper(s[i]);
        solve(i+1,temp,s,ans);
        temp.pop_back();
        temp+=tolower(s[i]);
        solve(i+1,temp,s,ans);
    }
}
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string temp="";
        vector<string>ans;
        solve(0,temp,s,ans);
        return ans;

        }
};
