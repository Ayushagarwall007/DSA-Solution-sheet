// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

// You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

// MountainArray.get(k) returns the element of the array at index k (0-indexed).
// MountainArray.length() returns the length of the array.
// Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

// Example 1:

// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
// Example 2:

// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.
 

// Constraints:

// 3 <= mountain_arr.length() <= 104
// 0 <= target <= 109
// 0 <= mountain_arr.get(index) <= 109




/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0; 
        int size = mountainArr.length();
        int high = size-1;
        int peak; // to store the index of the peak element

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mid==0) // if the index to check for peak is 0th { which can never be a peak index, we check the next element}
                mid = mid+1;
            else if(mid==size-1) // if the index to check for peak is last index { which can never be a peak index, we check for the previous element}
                mid = mid-1;

            int val = mountainArr.get(mid);
            int left = mountainArr.get(mid-1);
            int right = mountainArr.get(mid+1);
            if(val>right && val>left) // peak element condition satisfies
            {
                peak = mid;
                break;
            }
            else if(val>left && val<right) // current index's value is larger than its left and smaller than its right, i.e., on the increasing slope
            {
                low = mid+1;
            }
            else // current index's value is smaller than its left and larger than its right, i.e., on the decreasing slope
            {
                high = mid-1;
            }
        }

        if(target==mountainArr.get(peak)) // if the target element is at the peak
            return peak;
        

//BINARY SEARCH on the left subarray of the peak i.e., INCREASING SEQUENCE
        low = 0, high = peak-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            
            if(val==target)
                return mid;
            else if(val>target)
                high = mid-1;
            else
                low = mid+1;
        }
//BINARY SEARCH on right part to the peak i.e., DECREASING SEQUENCE
//BINARY SEARCH for DECREASING NUMBERS
        low = peak+1, high = size-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val==target)
                return mid;
            else if(val>target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};
