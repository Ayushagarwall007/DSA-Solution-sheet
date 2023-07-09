// You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

// Example:

// Input: 
// *-A/BC-/AKL
// Output: 
// ABC/-AK/L-*
// Explanation: 
// The above output is its valid postfix form.
// Your Task:

// Complete the function preToPost(string pre_exp), which takes a prefix string as input and returns its postfix form.

 

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=pre_exp.length()<=100


class Solution {
  public:
    string preToPost(string pre_exp) {
        
        stack <string> s;
        
        for (int i = pre_exp.size() -1; i>= 0; i--){
            
            if (pre_exp[i] == '+' || pre_exp[i] == '-' || pre_exp[i] == '*' || pre_exp[i] == '/' || pre_exp[i] == '^'){
                
                string a = s.top();
                s.pop();
                string b = s.top();
                s.pop();
                string c = a + b + pre_exp[i];
                s.push(c);
            }
            
            else{
                string d = "";
                d += pre_exp[i];
                s.push(d);
            }
        }
        
        return s.top();
    }
};
