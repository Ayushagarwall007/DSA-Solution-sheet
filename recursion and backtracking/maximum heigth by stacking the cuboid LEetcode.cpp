// 1691. Maximum Height by Stacking Cuboids 
// Hard
// 739
// 22
// Companies
// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

// Return the maximum height of the stacked cuboids.

 

// Example 1:



// Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
// Output: 190
// Explanation:
// Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
// Cuboid 0 is placed next with the 45x20 side facing down with height 50.
// Cuboid 2 is placed next with the 23x12 side facing down with height 45.
// The total height is 95 + 50 + 45 = 190.
// Example 2:

// Input: cuboids = [[38,25,45],[76,35,3]]
// Output: 76
// Explanation:
// You can't place any of the cuboids on the other.
// We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
// Example 3:

// Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
// Output: 102
// Explanation:
// After rearranging the cuboids, you can see that all cuboids have the same dimension.
// You can place the 11x7 side down on all cuboids so their heights are 17.
// The maximum height of stacked cuboids is 6 * 17 = 102.
 

// Constraints:

// n == cuboids.length
// 1 <= n <= 100
// 1 <= widthi, lengthi, heighti <= 100




// here we will first sort each of the dimensions on each blocks so the the maximum one will be the height of the each block and then we sort the whole 2D array on the basis of the length so that we can use the method of the longest increasing subsequence to pick or not pick that cuboid if safe  this is a way for the simple recursive approach for the allocation of the cuboid in the top of each other.
// this approach will give TLE and will optimize this with the help of DP.
class Solution {
public:
    bool isSafe(vector<vector<int>> &cuboids,int curr,int prev)
    {
        if(cuboids[curr][0]<=cuboids[prev][0] and cuboids[curr][1]<=cuboids[prev][1] and cuboids[curr][2]<=cuboids[prev][2]) return true;
        return false;
    }

    int solve(vector<vector<int>>& cuboids,int n,int curr,int prev)
    {
        if(curr<0) return 0;
        int pick=0;
        if(prev==-1 or isSafe(cuboids,curr,prev) )
        {
            pick=cuboids[curr][2]+solve(cuboids,n,curr-1,curr);
        }
        int notPick=0+solve(cuboids,n,curr-1,prev);

        return max(pick,notPick);

    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++)
        {
           sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        for(auto i:cuboids)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int ans=solve(cuboids,cuboids.size(),cuboids.size()-1,-1);
        return ans;
    }
};
