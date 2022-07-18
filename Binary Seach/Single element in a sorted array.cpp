// // You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.


class Solution {
public: int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid%2==0)
            {
                if(nums[mid]!=nums[mid+1])
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else if(mid%2!=0)
            {
                if(nums[mid]==nums[mid+1])
                    high=mid-1;
                else 
                    low=mid+1;
                    
            }
        }
        
        
        return nums[low];
        
        
    }
};
