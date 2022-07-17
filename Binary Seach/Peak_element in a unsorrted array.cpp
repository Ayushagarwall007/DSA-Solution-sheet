// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// APPROACH 01:
 class Solution {
    public: 
        int findPeakElement(vector<int>& nums) {
        
        int start =0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        
        while(start <= end)
        {
            
            mid = (start+end)/2;
            //edge cases, the cases when the mid is either of the ends 
             if(mid==0)
            {
                 if(mid == nums.size()-1)
                     return mid;
                if(nums[mid]>nums[mid+1])
                    return mid;
                 else start = mid+1;
            }
            else if (mid == nums.size()-1)
            {
                if(nums[mid] >nums[mid-1])
                return mid;
                else end = mid-1;}
                
                
            else 
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid]<nums[mid-1])
            {
                end = mid-1;
            }
            else if(nums[mid]<nums[mid+1])
            {
                start = mid+1;
            }
       
            
        }
        return mid;
        
    }
};








//APPROACH 02:- 
class Solution {
public:
int findPeakElement(vector<int>& nums) {
        vector<int>v=nums;
    int n=v.size();
    
    if (n==1)
        return 0;
    
    int lo=0,hi=n-1;
    
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if (mid==0)
        {
            if (v[mid+1]>v[mid])
                lo=mid;
            else
                return mid;
            continue;
        }
        if (mid==n-1)
        {
            if (v[mid-1]>v[mid])
                hi=mid;
            else return mid;
            continue;
        }
        if (v[mid]>v[mid-1] and v[mid]>v[mid]+1)
            return v[mid];
        else{
            if (v[mid]<v[mid-1]){
                hi=mid;
            }else
                lo=mid;
        }
        
        
    }
    cout << lo <<" "<<hi <<"\n";
    if (v[lo]>v[hi]) return lo;
    else return hi;
}
};
