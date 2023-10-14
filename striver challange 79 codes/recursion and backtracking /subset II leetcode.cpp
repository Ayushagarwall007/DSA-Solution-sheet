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




class Solution {
public:
void solve(int i,vector<int>&nums,set<vector<int>>&st,vector<int>temp)
{
    if(i>=nums.size())
    {
        st.insert(temp);
        return;
    }
    solve(i+1,nums,st,temp);
    temp.push_back(nums[i]);
    solve(i+1,nums,st,temp);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,st,temp);
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};



// class Solution {
// public:
// void solve(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&st)
// {
//     if(i==nums.size())
//     {
//         st.insert(temp);
//         return;
//     }
//     temp.push_back(nums[i]);
//     solve(i+1,nums,temp,st);
//     temp.pop_back();
//     solve(i+1,nums,temp,st);
// }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<vector<int>>ans;
//        vector<int>temp;
//        sort(nums.begin(),nums.end());
//        set<vector<int>>st;
//        solve(0,nums,temp,st);
//        for(auto i:st)
//        {
//            ans.push_back(i);
//        }
//        return ans;
//     }
// };
