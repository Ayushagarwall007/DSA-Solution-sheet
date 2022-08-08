// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0


#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
//     isme huum ye check kaarenge agar koi open and close bracket ke beech mai koi operator aaye to vo reduntant bracket nahi hai 
    
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/')
            st.push(ch);
        else
        {
            //yaa ch koi ) hai yaa koi lowercase letter hai
            if(ch==')')
            {
                bool isReduntant=true;
                while(st.top()!='(')
                {
                    char top=st.top();
                    if(top=='+'||top=='-'||top=='*'||top=='/')
                    {
                        isReduntant=false;
                    }
                    st.pop();
                    
                }
                if(isReduntant== true)
                    return true;
                st.pop();
            }
        }
        
    }
    return false;
}
