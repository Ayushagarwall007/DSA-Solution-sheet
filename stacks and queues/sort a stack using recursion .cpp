// given a stack ... you have to sort the stack without using any loop and has to sort the satck by swapping element in the stack itself


void sortedInsert(stack<int> &s,int num)
{
//     base case;
    if(s.empty() or (!s.empty() and s.top()<num))
    {
        s.push(num);return;
    }
    int n=s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(n);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
//     using recursion
//     base case
    if(stack.empty())
    {
        return;
    }
    int num=stack.top();
    stack.pop();
//     recursive call
    sortStack(stack);
    sortedInsert(stack,num);
    
    
    
    
}
