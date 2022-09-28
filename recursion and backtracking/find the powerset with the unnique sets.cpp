// 90. Subsets II
// Medium

// 6663

// 185

// Add to List

// Share
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

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
    vector<vector<int>>m;
    set<vector<int>>s;
    void solve(vector<int>nums,vector<int>v)
    {
        if(nums.size()==0)
        {
            
            if(s.find(v)==s.end())
            {
            
                s.insert(v);
                m.push_back(v);
                
            }
            return ;
        }
        vector<int>v1=v,v2=v;
        v1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,v1);
        solve(nums,v2);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        sort(nums.begin(),nums.end());
        solve(nums,op);
        return m;
        
    }
};
