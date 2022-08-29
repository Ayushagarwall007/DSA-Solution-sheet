// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.


class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int num=0;
        char sign='+';
        int pre;
        for(int i=0;i<s.size();i++)
        {
            char c= s[i];
            if(isdigit(c))
            {
                num=num*10+(c-'0');
            }
           if(c=='+'||c=='-'||c=='*'||c=='/'||i==s.size()-1){
            switch(sign){
                case '+':
                    stack.push(num);
                    break;
                case '-':
                    stack.push(-num);
                    break;
                case '*':
                    pre = stack.top();
                    stack.pop();
                    stack.push(pre*num);
                    break;
                case '/':
                    pre = stack.top();
                    stack.pop();
                    stack.push(pre/num);
                    break;
            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    while(!stack.empty()){
        res = res+stack.top();
        stack.pop();
    }
    return res;
}
};
