// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100









// Approach 1:
// Step 1: Linearly traverse the array from backwards so that the array's ith index value is less than the array's (i+1)th index value. Store  that index into a variable.
// Step 2: If the index value obtained in step 1 is less than zero. This indicates that the given input array has already been sorted in descending order. Simply reverse the given array to obtain the next permutation. Otherwise, simply traverse the array backwards to find the index that has a value greater than the previously found index. Store index in another variable.
// Step 3: Swap values present in indices found in the above two steps.
// Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size(),i,j;
        for(i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]) break;
        }
        if(i<0) reverse(arr.begin(),arr.end());
        else{
            for(j=n-1; j>=0; j--){
                if(arr[j]>arr[i]) break;
            }
            swap(arr[i],arr[j]);
            reverse(arr.begin()+i+1,arr.end());
        }
    }
};
