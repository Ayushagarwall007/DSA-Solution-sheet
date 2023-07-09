// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104




// class Solution {
// public:
// vector<int>nextSmallerElement(vector<int>arr,int n)
// {
//     stack<int>st;
//     // int n=arr.size();
//     vector<int>res(n,-1);
//     for(int i=0;i<n;i++)
//     {
//         int curr=arr[i];
//         while(!st.empty() and arr[st.top()]>curr)
//         {
//             res[st.top()]=i;
//             st.pop();

//         }
//         st.push(i);
//     }
//     return res;
// }

// vector<int>prevSmallerElement(vector<int>arr,int n)
// {
//     stack<int>st;
//     vector<int>res(n,-1);
//     for(int i=n-1;i>=0;i--)
//     {
//          int curr=arr[i];
//         while(!st.empty() and arr[st.top()]>curr)
//         {
//             res[st.top()]=i;
//             st.pop();

//         }
//         st.push(i);
//     }
//     return res;
// }


//     int largestRectangleArea(vector<int>& ht) {
//         int n=ht.size();
//         vector<int>next(n);
//         next=nextSmallerElement(ht,n);

//         vector<int>prev(n);
//         prev =prevSmallerElement(ht,n);


//         for(auto i:next)
//         {
//             cout<<i<<" ";
//         }
//         cout<<"\n";
//         for(auto i:prev)
//         {
//             cout<<i<<" ";
//         }

//         int area=INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             int l=ht[i];
//             if(next[i]==-1)next[i]=n;
//             int b = next[i]-prev[i]-1;
//             int newArea=l*b;
//             area=max(area,newArea); 
//         }
//     return area;
//     }
// };




// bar ko left or right extand jaab taak kaaro jaab taak next smaller element in left and right side nahi aata hoo or phir total breadth ko usss particular length se multiply kaarke largest rectangle area nikaal loo 
// we will use the concept agar left side mai smaller length kaa index or right side mai  smaller length kaa index ko subtract kaakr humm breadth nikaal sakte hai
class Solution {
    private:
    vector<int>nextSmallerElement(vector<int> arr,int n)
    {
        stack<int> s;
         s.push(-1);
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--)
        {
            int curr=arr[i];
            while(s.top()!=-1&& arr[s.top()]>=curr) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    vector<int>prevSmallerElement(vector<int> arr,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);
        
        for(int i=0;i<=n-1;i++)
        {
            int curr=arr[i];
            while(s.top()!=-1&& arr[s.top()]>=curr) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& ht) {
        int n=ht.size();       
        
        vector<int>next(n);
        next=nextSmallerElement(ht,n);
        
        vector<int>prev(n);
        prev=prevSmallerElement(ht,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=ht[i];
            
            if(next[i]==-1)next[i]=n;
            int b=next[i]-prev[i]-1;
            
            int newArea=l*b;
            area=max(area,newArea);
        }
        
        return area;
    }
};

