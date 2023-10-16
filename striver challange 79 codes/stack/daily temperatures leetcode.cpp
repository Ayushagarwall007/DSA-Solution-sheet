// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n=temperatures.size();
       vector<int>ans(n,0);
       stack<int>stk;
       for(int i=n-1;i>=0;i--)
       {
           while(!stk.empty() and temperatures[stk.top()]<=temperatures[i])
           {
               stk.pop();
           }
           if(!stk.empty())
           {
               ans[i]=stk.top()-i;
           }
           stk.push(i);
       }
       return ans;
    }
};


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         stack<pair<int,int>>st;
//         int n=temp.size;
        
//         for(int i=0;i<n;i++)
//         {
//             while(!st.empty() and st.top().first<temp[i])
//             {
//                 temp[st.top().second]=i-st.top().second;
//                 st.pop();
//             }
//             st.push({temp[i],i});
//         }
//         while(!st.empty())
//         {
//             temp[st.top().second]=0;
//             st.pop();
//         }
//         return temp;
//     }
// };

