// You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

// The number of global inversions is the number of the different pairs (i, j) where:

// 0 <= i < j < n
// nums[i] > nums[j]
// The number of local inversions is the number of indices i where:

// 0 <= i < n - 1
// nums[i] > nums[i + 1]
// Return true if the number of global inversions is equal to the number of local inversions.

 

// Example 1:

// Input: nums = [1,0,2]
// Output: true
// Explanation: There is 1 global inversion and 1 local inversion.
// Example 2:

// Input: nums = [1,2,0]
// Output: false
// Explanation: There are 2 global inversions and 1 local inversion.
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 0 <= nums[i] < n
// All the integers of nums are unique.
// nums is a permutation of all the numbers in the range [0, n - 1].




class Solution {
public:
    long long countAndMerge(vector<int>& arr, long long low, long long mid, long long high) {
        long long n1 = mid - low + 1;
        long long n2 = high - mid;
        long long left[n1], right[n2];
        //Split the array and store them in left and right
        for(int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for(int i = 0; i < n2; i++) {
            right[i] = arr[mid + 1 + i];
        }
     long long count = 0, i = 0, j = 0, k = low;
        while(i < n1 and j < n2) {
            if(left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
                count += (n1 - i);
            }
            k++;
        }
        while(i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
        return count;
    }
    long long countGlobalInversions(vector<int>& nums, long long low, long long high) {
        long long res = 0, mid;
        if(low < high) {
            mid = low + (high-low)/2;
            res += countGlobalInversions(nums, low, mid);
            res += countGlobalInversions(nums, mid+1, high);
            res += countAndMerge(nums, low, mid, high);
        }
        return res;
    }
    long long countLocalInversions(vector<int>& nums, long long n) {
        long long count = 0;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1])
                count++;
        }
        return count;
    }
    bool isIdealPermutation(vector<int>& nums) {
        long long n = nums.size();
        long long local = countLocalInversions(nums, n);
        long long global = countGlobalInversions(nums, 0, n-1);
        if(local == global)
            return true;
        return false;
    }
};
