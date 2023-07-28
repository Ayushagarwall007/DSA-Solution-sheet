// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)




class Solution {
public:
bool solve(vector<int>&nums,int k,int mid)
{
    int sum=0;
    int no=1;
    for(auto i:nums)
    {
        if(sum+i<=mid)
        {
            sum+=i;
        }
        else
        {
            no++;
            sum=i;
        }
    }
    return no<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(solve(nums,k,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res;
    }
};
