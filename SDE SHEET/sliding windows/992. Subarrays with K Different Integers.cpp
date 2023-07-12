// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i], k <= nums.length




class Solution {
public:
int solve(vector<int>&arr,int k)
{
    int i=0;
    int j=0;
    int count=0;
    unordered_map<int,int>mp;
    while(j<arr.size())
    {
        mp[arr[j]]++;
        if(mp.size()<=k)
        {
            count+=j-i+1;
            j++;
        }
        else
        {
            while(mp.size()>k)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                {
                    mp.erase(arr[i]);
                }
                i++;
            }
            if(mp.size()<=k)
            {
                count+=j-i+1;
            }
             j++;
        }
       
    }
    return count;
    
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=solve(nums,k);//number of subarrays with at most k elements
        int b=solve(nums,k-1);
        return a-b;
    }
};
