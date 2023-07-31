// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.


class Solution {
public:
void solve(int ind,string s ,  vector<vector<string>>&ans , vector<string>temp)
{
    if(ind==s.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<s.size();i++)
    {
        if(isPalin(ind,i,s))
        {
            temp.push_back(s.substr(ind,i-ind+1));
            solve(i+1,s,ans,temp);
            temp.pop_back();
        }
    }
}
bool isPalin(int start,int end, string s)
{
    int i=start;
    int j=end;
    while(i<=j)
    {
        if(s[i++]!=s[j--])
        {
            return false;
        }
        
    }
    return true;
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ans,temp);
        return ans;

    }
};
