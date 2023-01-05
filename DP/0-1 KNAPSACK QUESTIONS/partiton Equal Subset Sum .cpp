// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false 
// otherwise.


// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100


// iss question mai humee total sum ko 2 equal part mai divivde kaarna hai to uska matlaab hai ki agar humme aisa kaarna hai to humme given array kaa total sum even 
// chaiye tabhi hum usko equal part ke 2 mai divide kaar sakte hai ....
// agar total sum odd hua to partition possible nahi hai ...
// phir humm subset sum approACH lagani hai for sum = total_sum/2 ke liye

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        else 
        sum=sum/2;
        bool dp[n+1][sum+1];
         for(int i=0 ; i<=n ; i++){
           dp[i][0]=1 ; 
       }
       for(int i=0 ; i<=sum ; i++){
           dp[0][i]=0 ;
       }
       dp[0][0]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
