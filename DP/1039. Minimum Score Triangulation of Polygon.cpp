// 1039. Minimum Score Triangulation of Polygon
// Medium
// 1.4K
// 142
// Companies
// You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

// You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

// Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

// Example 1:


// Input: values = [1,2,3]
// Output: 6
// Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
// Example 2:


// Input: values = [3,7,4,5]
// Output: 144
// Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
// The minimum score is 144.
// Example 3:


// Input: values = [1,3,1,4,1,5]
// Output: 13
// Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

// Constraints:

// n == values.length
// 3 <= n <= 50
// 1 <= values[i] <= 100



class Solution {
public:
int solve(vector<int>&values,int i,int j,vector<vector<int>>&dp)
{
    if(i+1==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        ans=min(ans,((values[i]*values[j]*values[k])+solve(values,i,k,dp)+solve(values,k,j,dp)));

    }
    return dp[i][j]=ans;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,values.size()-1,dp);
    }
};
