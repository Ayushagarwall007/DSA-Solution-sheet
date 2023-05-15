// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.




// solving it with the help of dutch national flag algorithm
// we will use 3 pointers
// low intitized at 0th pos
// mid  intitized at 0th pos
// high  intitized at n-1th pos

// abb algo chalaege ki
// [0....low-1] -> all zerors
// [low....mid-1] -> all ones
// [mid....high-1] -> 0/1/2
// [high....last] -> all twos

// aab 0 se mid-1 tkk saare sorted hai
// or high-1 se last saare sorted hai...
// or mid se high-1 tkk unsorted hai....


// algo:-
// if a[mid]==0   -> swap(a[low],a[mid]) low++, mid++;
// if(a[mid]==1)   -> mid++
// if(a[mid]==2)   -> swap(a[mid],a[high]) high--;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)mid++;
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};
