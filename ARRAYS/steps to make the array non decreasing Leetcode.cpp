// 2289. Steps to Make Array Non-decreasing
// Medium


// You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

// Return the number of steps performed until nums becomes a non-decreasing array.

 

// Example 1:

// Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
// Output: 3
// Explanation: The following are the steps performed:
// - Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
// - Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
// - Step 3: [5,4,7,11,11] becomes [5,7,11,11]
// [5,7,11,11] is a non-decreasing array. Therefore, we return 3.
// Example 2:

// Input: nums = [4,5,7,7,13]
// Output: 0
// Explanation: nums is already a non-decreasing array. Therefore, we return 0.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109



class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans=0;
        
        stack<pair<int,int>>s;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(s.empty())s.push({nums[i],0});
            
            else{
                int a=0;
                while(!s.empty() && s.top().first<nums[i]){
                    a=max(a+1,s.top().second);
                    s.pop();
                }
                s.push({nums[i],a});
                ans=max(ans,a);
            }
        }
        
        return ans;
    }
};
