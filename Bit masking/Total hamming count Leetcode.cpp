// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

// Example 1:

// Input: nums = [4,14,2]
// Output: 6
// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case).
// The answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// Example 2:

// Input: nums = [4,14,4]
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 109
// The answer for the given input will fit in a 32-bit integer.



class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;int n=nums.size();
        if(n<=1)return 0;
        for(int i=0;i<32;i++)
        {
            int one=0,zero=0;
            int k=(1<<i);

            for(int j=0;j<n;j++)
            {
                if(nums[j]&k) one++;
                if((nums[j]&k)==0) zero++;

                
            }
            if(one==n or zero==n) continue;
            else
            ans+=(one*zero);
        }
        return ans;
    }
};
