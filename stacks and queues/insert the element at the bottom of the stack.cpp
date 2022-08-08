// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0


void solve (stack<int>& st, int x) 
{
    // base case
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int num=st.top();
    st.pop();
//     recursive call
    solve(st,x);
    st.push(num);
    
    
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
//     we will use recursion here to first store every top element and than acc to base case it will add the element at the bottom of the stack and then push back all
//         the other elements while returning from the recursive cases
    
    solve(myStack,x);
    return myStack;
    
}
