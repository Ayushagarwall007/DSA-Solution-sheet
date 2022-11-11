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
    vector<string> ans;
    void solve(int open ,int close,string op)
    {
        if(open==0 and close==0)
        {
            ans.push_back(op);
            return;
        }
        
        if(open!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1);
        }
        if(close>open)
        {
            string op1=op;
            op1.push_back(')');
            solve(open,close-1,op1);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        string op="";
        solve(open,close,op);
        return ans;
    }
};

// // supose humm n=3 lete hai to humpe 6 baxes hai to humme har box ke liye choice hai yaa to open braces loo yaa close brachumess loo
// aab humm input and output walla recursive approach laagaenge or output mai string lenge or input mai nuber of open braces and number of close braces lenge 

// aab hum string start open braces se kaarenge or humm hur  new string mai permutaion lagaenge open or close ke liye or agar open == close hota hai to hum sirf open output mai add karenge or agar nuber of open braces < number of close braces hota hai to hum dono permuation laagenge or phir recursive call lenge
