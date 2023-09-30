// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109





class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1=0;
        int cnt1=0;
        int ele2=0;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 and ele2!=nums[i])
            {
                cnt1++;
                ele1=nums[i];
            }
            else if(cnt2==0 and ele1!=nums[i])
            {
                cnt2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            {
                cnt1++;
            }
            else if(nums[i]==ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ans;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])cnt1++;
            if(ele2==nums[i])cnt2++;
        }

        if(cnt1>(n/3))ans.push_back(ele1);
        if(cnt2>(n/3))ans.push_back(ele2);

        return ans;
    }
};
