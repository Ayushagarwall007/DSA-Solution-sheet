// program to find the maximum subarray sum in the given array....
//Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN,sum = 0;
        for(int &x:nums){
            sum += x;
            ans = max(ans,sum);
            sum = max(sum,0);
        }
        return ans;
    }
};


// DP Approach
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) 
//         int ans = nums[0];
//         for(int i = 1; i < nums.size(); i++){
//             nums[i] = max(nums[i],nums[i-1]+nums[i]);
//             ans = max(ans,nums[i]);
//         }
//         return ans;
//     }
// };
