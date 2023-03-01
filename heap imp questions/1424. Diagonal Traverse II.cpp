// Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

// Example 1:


// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,4,2,7,5,3,8,6,9]
// Example 2:


// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i].length <= 105
// 1 <= sum(nums[i].length) <= 105
// 1 <= nums[i][j] <= 105



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey = 0;
        unordered_map<int, vector<int>> map;
        for (int r = nums.size() - 1; r >= 0; --r) { // The values from the bottom rows are the starting values of the diagonals.
            for (int c = 0; c < nums[r].size(); ++c) {
                map[r + c].push_back(nums[r][c]);
                maxKey = max(maxKey, r + c);
            }
        }
        vector<int> ans;
        for (int key = 0; key <= maxKey; ++key)
            for (int v : map[key]) ans.push_back(v);
        return ans;
    }
};
