// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0


#include<stack>
int findMinimumCost(string str) {
  // Write your code here
//     if the length of the string is oddd then return -1 ie it is impossible to make a string valid
//         conditions for a valid string:-
//            1= number of open =number of closes
//             2= every close brace should have the open brace before it
            
//                phle saari valid string ko remove kaar do jo baachegi vo invalid string hgii...
//                    atq invalid strings are:-}{},}}}}},{{{{,
    
//     odd condition 
    if(str.length()&1)return -1;
    
    stack<char>s;
    for(int i=0;i<str.length();i++)
    {
        char ch= str[i];
        if(ch=='{') s.push(ch);
        else
        {
//             ch is close braces
            if(!s.empty()&&s.top()=='{') s.pop();
            else s.push(ch);
        }
       }
     // now stack contains invalid characters string combinations
        int a=0,b=0;// here b is count for the open brace and a is the count for the close brace
        while(!s.empty())
        {
            if(s.top()=='{')b++;
            else a++;
            s.pop();
        }
        int ans=(a+1)/2 + (b+1)/2;
        return ans;
}
