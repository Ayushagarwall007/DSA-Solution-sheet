// You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

// Example:

// Input:
// ab*c+ 
// Output: 
// ((a*b)+c)
// Explanation: 
// The above output is its valid infix form.
// Your Task:

// Complete the function string postToInfix(string post_exp), which takes a postfix string as input and returns its infix form.

 

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=post_exp.length()<=104



class Solution {

  public:

  

    bool isOperator(char c)

    {

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

        {

            return false;

        }

        return true;

    }

    

    string postToInfix(string exp) {

        // Write your code here

        

        stack<string> st;

        string res;

        

        for(int i=0;i<exp.length();i++)

        {

            char c = exp[i];

            

            if(isOperator(c))

            {

                string str1 = st.top();

                st.pop();

                

                string str2 = st.top();

                st.pop();

                

                st.push('(' + str2 + exp[i] + str1 + ')');

            }

            else

            {

                st.push(string(1,exp[i]));

            }

        }

        

        while(!st.empty())

        {

            res += st.top();

            st.pop();

        }

        

        return res;

    }

};
