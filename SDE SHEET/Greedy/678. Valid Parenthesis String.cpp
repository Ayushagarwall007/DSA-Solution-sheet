// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "(*)"
// Output: true
// Example 3:

// Input: s = "(*))"
// Output: true
 

// Constraints:

// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.




class Solution {
public:
    bool checkValidString(string s) {
        stack<int>left;
        stack<int>star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(!left.empty())left.pop();
                else if(!star.empty())star.pop();
                else return false;
            }
            else if(s[i]=='(')
            {
                left.push(i);
            }
            else
            {
                star.push(i);
            }
        }
        while(!left.empty() and !star.empty())
        {
            if(left.top()>star.top())
            {
                return false;
            }
            left.pop();
            star.pop();
        }

            if(!left.empty())return false;
            
        
        return true;
    }
};
