// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10


// class Solution {
// public:
// void solve(vector<int>&nums,int index,set<vector<int>>&s,vector<int>output)
// {
//     if(index>=nums.size())
//     {
//         s.insert(output);
//         return;
//     }
//     solve(nums,index+1,s,output);//not take
//     output.push_back(nums[index]);
//     solve(nums,index+1,s,output);//take
// }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>ans;
//         vector<int>output;
//         set<vector<int>>s;
//         int index=0;
//         solve(nums,index,s,output);
//         for(auto i:s)
//         {
//             ans.push_back(i);
//         }
// //         return ans;
//     }
// };



class Solution {
public:
void solve(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&st)
{
    if(i==nums.size())
    {
        st.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(i+1,nums,temp,st);
    temp.pop_back();
    solve(i+1,nums,temp,st);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>temp;
       sort(nums.begin(),nums.end());
       set<vector<int>>st;
       solve(0,nums,temp,st);
       for(auto i:st)
       {
           ans.push_back(i);
       }
       return ans;
    }
};
