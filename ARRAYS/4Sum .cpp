// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            long long t1 = target - nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                long long t2 = t1 - nums[j];
                int l = j+1, r = nums.size()-1;
                while(l < r){
                    int val = nums[l] + nums[r];
                    if(val < t2)
                        l++;
                    else if(val > t2)
                        r--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        while(nums[l] == nums[l-1] and l < r)
                            l++;
                    }
                }
            }
        }
        return ans;
    }
};
