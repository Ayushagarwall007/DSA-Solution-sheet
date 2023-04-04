// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104




class Solution {
public:
    int threeSumClosest(vector<int>& a, int x) {
        sort(a.begin(), a.end());
        int res, diff = INT_MAX;
        for(int i = 0; i < a.size(); i++) {
            int l = i + 1, r = a.size() - 1;
            while(l < r ) {
                int s = a[i] + a[l] + a[r];
                if(abs(s - x) < diff) {
                    diff = abs(s - x);
                    res = s;
                }
                if(s > x) r--;
                else l++;
            }
            // cout << endl;
        }
        return res;
    }
};
