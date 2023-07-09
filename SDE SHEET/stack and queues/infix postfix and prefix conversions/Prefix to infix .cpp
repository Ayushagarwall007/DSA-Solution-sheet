// You are given a string S of size N that represents the prefix form of a valid mathematical expression. Convert it to its infix form.

// Example 1:

// Input: 
// *-A/BC-/AKL
// Output: 
// ((A-(B/C))*((A/K)-L))
// Explanation: 
// The above output is its valid infix form.
// Your Task:

// Complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.

 

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=|S|<=104



class Solution {
  public:
    string preToInfix(string s) {
        int n=s.size();
        string ans;
        stack<string>st;
        
        for(int i=n-1;i>=0;i--)
        {
            char ch=s[i];
            if(ch>='a' and ch<='z' || ch>='A' and ch<='Z' || ch>='1' and ch<='9')
            {
                string temp="";
                temp=temp+ch;
                st.push(temp);
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string res="";
                res+='('+a+ch+b+')';
                st.push(res);
            }
            
        }
        ans=st.top();
        return ans;
    }
};
