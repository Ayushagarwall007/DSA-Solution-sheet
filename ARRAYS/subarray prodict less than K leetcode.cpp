// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// 1 <= nums[i] <= 1000
// 0 <= k <= 106

// this  question is basically a variable size sliding window question  
class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& array, int value) {
        
        if(value<=1)return 0;
        int i=0;
        int j=0;
        int p=1;
        int subarrays=0;
        
        
        int n=array.size();
        while(j<n)
        {
            p*=array[j];
            
            if(p<value)
            {
                subarrays+=(j-i+1);
                j++;
            }
            else
            {
                while(p>=value)
                {
                    p=p/array[i];
                    i++;
                }
                subarrays+=(j-i+1);
                j++;
            }
        }
        return subarrays;
    }
};
