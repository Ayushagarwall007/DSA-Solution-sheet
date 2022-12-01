// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in-place.

// Example 1:

// Input: matrix = {{0,25},{-1,0}}

// Output: {{0,25},{-1,0}}

// Explanation: The shortest distance between
// every pair is already given(if it exists).
// Example 2:

// Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

// Output: {{0,1,7},{1,0,6},{-1,-1,0}}

// Explanation: We can reach 2 from 0 as 0->1->2
// and the cost will be 1+6=7 which is less than 
// 43.
// Your Task:
// You don't need to read, return or print anything. Your task is to complete the function shortest_distance() which takes the matrix as input parameter and modifies the distances for every pair in-place.

// Expected Time Complexity: O(n3)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n <= 100
// -1 <= matrix[ i ][ j ] <= 1000


// ṃultisource shortest path algorithm 
// using the concept of the precomputation
// detection of the negative cycle
// go via every vertex
// cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j])

//to detect the negative cycle in the graph we see if for any node if the cost[i][i]<0 that means the graph contais the negative cycle

// min(d[i][k]+d[j][k])

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            {
	                matrix[i][j]=1e9;
	            }
	            if(i==j) matrix[i][j]==0;
	        }
	    }
	    for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
	    
	   // to check for the negative cycle in the graph
	   //for(int i=0;i<n;i++)
	   //{
	   //    if(matrix[i][i]<0) then print that the negative cycle exists in the graph
	   //}
	    
	    
	     for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            {
	                matrix[i][j]=-1;
	            }
	           
	        }
	    }
	    
	}
};
