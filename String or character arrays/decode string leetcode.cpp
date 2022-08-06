// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
 

// Constraints:

// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].



class Solution {
public:
    string decodeString(string s) {
        
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                string temp="";
                while(!st.empty() && st.top()!='[')
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top()))
                {
                    num=st.top()+num;
                    st.pop();
                }
                int x=stoi(num);
                string temp1="";
                while(x--)
                  temp1=temp1+temp;
                for(int j=0;j<temp1.size();j++)
                    st.push(temp1[j]);
            }
            else
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
