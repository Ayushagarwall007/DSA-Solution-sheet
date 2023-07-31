// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8


class Solution {
public:
vector<string>ans;
   void generate (int open,int close ,int n,string s){
       if(s.size()==2*n)ans.push_back(s);
       if(open<n)generate(open+1,close,n,s+"(");
       if(close<open)generate(open,close+1,n,s+")");
   }
    vector<string> generateParenthesis(int n) {
        generate(0,0,n,"");
        return ans;
    }
};


class Solution {
public:
void solve(int sopen,int sclose,int openLeft,int closeLeft,string &temp,vector<string>&ans)
{
    if(openLeft==0 and closeLeft==0)
    {
        ans.push_back(temp);
    }
    if(openLeft>0)
    {
        temp.push_back('(');
        solve(sopen+1,sclose,openLeft-1,closeLeft,temp,ans);
        temp.pop_back();
    }
    if(closeLeft>0 and sopen>sclose)
    {
        temp.push_back(')');
        solve(sopen,sclose+1,openLeft,closeLeft-1,temp,ans);
        temp.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int sopen=1;
        int sclose=0;
        int openLeft=n-1;
        int closeLeft=n;
        string temp="(";
        solve(sopen,sclose,openLeft,closeLeft,temp,ans);
        return ans;
    }
};
