#include<bits/stdc++.h>
void reverse(stack<int>&s,stack<int>ss)
{
    if(s.empty())
    {
        s=ss;
        return;
    }
    ss.push(s.top());
    s.pop();
    return reverse(s,ss);
}
void reverseStack(stack<int> &s) {
    stack<int>ss;
    reverse(s,ss);
}
