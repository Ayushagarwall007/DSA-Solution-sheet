
// Topics
// Companies
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.




class Solution {
public:
void solve(vector<int>&nums,int i, vector<int>temp,vector<vector<int>>&ans)
{
    if(i>=nums.size())
    {
        ans.push_back(temp);
        return;
    }
    // solve(nums,i+1,temp,ans);
    temp.push_back(nums[i]);
    solve(nums,i+1,temp,ans);
    temp.pop_back();
    solve(nums,i+1,temp,ans);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};



// class Solution {
// public:
// void solve(vector<int>&nums,int i, vector<int>temp,vector<vector<int>>&ans)
// {
//     if(i>=nums.size())
//     {
//         ans.push_back(temp);
//         return;
//     }
//      solve(nums,i+1,temp,ans);//not take
//     temp.push_back(nums[i]);
//     solve(nums,i+1,temp,ans);//take
    
    
// }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         solve(nums,0,temp,ans);
//         return ans;
//     }
// };
