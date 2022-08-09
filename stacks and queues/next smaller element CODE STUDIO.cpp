// // https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
// -> first we iterate from right to left to make the number of comparisions easier
// ->Then first we instaialize the top of the stack with -1 so that the next smaller element to the right of the right most element is -1
//  -> then after iterating the next element from the right we will see  that the top of the stack is the element smaller than the current element
//  -> if not then we will pop the elements till we did not get the smaller element smaaler than the current elemnet
//  ->after getting the smaaler elemet just push the current element into the stack to iterate over the next element fron the right to the left
 

#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   stack<int> s;
    s.push(-1);// initially stack mai -1 push kaar do bec right most element ke liye smallest element -1 hotaa hai
    vector<int>ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(s.top()>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
    
}
