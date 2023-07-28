// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109




class Solution {
public:
int first_occ(vector<int>&nums,int target)
{
    int ans=-1;
    int left=0;
    int right=nums.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
        {
            ans=mid;
            right=mid-1;
        }
        else if(nums[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
        
    }
    return ans;
}
    int last_occ(vector<int>&nums,int target)
    {
    int ans=-1;
    int left=0;
    int right=nums.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
        {
            ans=mid;
            left=mid+1;
        }
        else if(nums[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
        
    }
    return ans;

    }



    vector<int> searchRange(vector<int>& nums, int target) {
        int first=first_occ(nums,target);
        int last=last_occ(nums,target);
        return {first,last};
    }
};
