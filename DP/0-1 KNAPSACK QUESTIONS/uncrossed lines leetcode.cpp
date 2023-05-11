// You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

// Return the maximum number of connecting lines we can draw in this way.

 

// Example 1:


// Input: nums1 = [1,4,2], nums2 = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
// Example 2:

// Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
// Output: 3
// Example 3:

// Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
// Output: 2




class Solution {
public:
int solve(int i,int j,vector<int>&nums1,vector<int>nums2,vector<vector<int>>&dp)

{
    if(i==nums1.size() || j==nums2.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int count=0;
    // take
    if(nums1[i]==nums2[j])
    {
        count=1+solve(i+1,j+1,nums1,nums2,dp);
    }
    else
    {
        count+=max(solve(i+1,j,nums1,nums2,dp) , solve(i,j+1,nums1,nums2,dp));

    }
    return dp[i][j]= count;
}
// int solve2(vector<int>&nums1,vector<int>&nums2)
// {
//     vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
    
//     for(auto i=nums1.size()-1;i>=0;i--)
//     {
//         for(auto j=nums2.size()-1;j>=0;j--)
//         {
//             int count=0;
//             if(nums1[i]==nums2[j]) 
//             {
//                 count=1+dp[i+1][j+1];
//             }
//             else 
//             {
//                 count+=max(dp[i+1][j],dp[i][j+1]);
//             }
//             dp[i][j]=count;
//         }
        
//     }
//     return dp[0][0];
// }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+2,vector<int>(nums2.size()+2,-1));
        return solve(0,0,nums1,nums2,dp);
        
        // return solve2(nums1,nums2);
        
    }
};
