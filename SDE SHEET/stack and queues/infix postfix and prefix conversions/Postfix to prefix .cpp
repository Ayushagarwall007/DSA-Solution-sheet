// You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

// Example:

// Input: 
// ABC/-AK/L-*
// Output: 
// *-A/BC-/AKL
// Explanation: 
// The above output is its valid prefix form.
// Your Task:

// Complete the function string postToPre(string post_exp), which takes a postfix string as input and returns its prefix form.

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=post_exp.length()<=1000



class Solution {
  public:
    string postToPre(string post) {
        stack<string>s;
        int size=post.size();
        int i=0;
        while(i<size)
        {
            if(post[i]=='+' or post[i]=='-' or post[i]=='*' or post[i]=='/')
            {
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                string btw=post[i]+s2+s1;
                s.push(btw);
                i++;
            }
            else
            {
                string str;
                str+=post[i];
                s.push(str);
                i++;
            }
        }
        return s.top();
    }
};
