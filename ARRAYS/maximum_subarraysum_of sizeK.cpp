// cpp program to find the maximum subarray sum of size k ie k is the size of the subarray
 class Solution {
public:
    int  maxSlidingWindow(vector<int>& nums, int k) {
        int size=nums.size();
      
      if(size<k)
      {
        // the sum is not possible
        return 0;
      }
        int i=0,j=0;
        vector<int>ans;
      int sum=0;
        int maxi=INT_MIN;;
        while(j<size)
        {
            sum=sum+nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
              sum=sum-nums[i];
               maxi=max(maxi,sum);
               i++;j++;
            }
        }
        return maxi;
    }
};
