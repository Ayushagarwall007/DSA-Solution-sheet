// you are given the integer n find all the binary strings containg 0 and 1 of size n such that there is not any concequtive ones 


#include<bits/stdc++.h>
void solve(int n,int ind,vector<string>&ans,string temp)
{
    if(ind==n)
    {
        ans.push_back(temp);
        return;
    }
    solve(n,ind+1,ans,temp+'0');
    if(temp=="" or temp.back()=='0')
    solve(n,ind+1,ans,temp+'1');
    
}
vector<string> generateString(int n) {
    // Write your code here.
    vector<string>ans;
    string temp="";
    int ind=0;
    solve(n,ind,ans,temp);
    return ans;
}
