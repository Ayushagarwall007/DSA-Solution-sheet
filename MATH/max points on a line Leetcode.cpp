// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:


// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
 

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.




class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)

        return points.size();


        int ans=INT_MIN;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];

                int count =0;

                for(int k=0;k<points.size();k++)
                {
                    
                                int a=dx*(points[k][1]-points[i][1]);
                                int b=dy*(points[k][0]-points[i][0]);
                                if(a==b)
                                        count++;
                }
                ans=max(ans,count);
            }

        }
        return ans;
    }
};
