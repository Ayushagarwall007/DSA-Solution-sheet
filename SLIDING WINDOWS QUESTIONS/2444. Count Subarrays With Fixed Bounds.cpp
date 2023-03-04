// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
// Example 2:

// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

// Constraints:

// 2 <= nums.length <= 105
// 1 <= nums[i], minK, maxK <= 106




class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long count=0;
        int mini=-1,maxi=-1;
        int i=0,j=0;
        while(j<n)
        {
            if(nums[j]<minK or nums[j]>maxK)
            {
                mini=maxi=-1;
                i=j+1;
            }
            if(nums[j]==minK)mini=j;
            if(nums[j]==maxK)maxi=j;
            count+=max(0,min(mini,maxi)-i+1);
            j++;
        }
        return count;
    }
};
