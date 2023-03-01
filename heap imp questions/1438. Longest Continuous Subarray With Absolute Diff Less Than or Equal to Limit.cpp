// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        priority_queue<pair<int,int>>max_heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>min_heap;
        int left=0,ans=0;
        for(int right=0;right<n;right++)
        {
            max_heap.push({nums[right],right});
            min_heap.push({nums[right],right});
        
        while(max_heap.top().first-min_heap.top().first>limit)
        {
            left++;
            while(!max_heap.empty() && max_heap.top().second<left)
            max_heap.pop();
            while(!min_heap.empty() and min_heap.top().second<left)
            min_heap.pop();
        }
        ans=max(ans,right-left+1);
        }
        return ans;
    }
};




class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        int j=0;
        int maxSize=0;
        multiset<int>ms;
        while(j<nums.size())
        {
            ms.insert(nums[j]);
            auto max=*ms.rbegin();
            auto min=*ms.begin();
            if(abs(max-min)<=limit){}
            else
            {
                while(i<=j and abs(max-min)>limit)
                {
                    ms.erase(ms.find(nums[i]));
                    i++;
                    max=*ms.rbegin();
                    min=*ms.begin();
                }
            }
            maxSize=std::max(maxSize,j-i+1);
            j++;
        }
        return maxSize;
    }
};
