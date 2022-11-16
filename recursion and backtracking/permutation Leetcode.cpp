// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.


class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int> nums,int l,int r)
{
    if(l==r)
    {
        ans.push_back(nums);
        return;
    }
    for(int i=l;i<=r;i++){
    swap(nums[l],nums[i]);
    solve(nums,l+1,r);
    swap(nums[l],nums[i]);
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
        return ans;
    }
};
