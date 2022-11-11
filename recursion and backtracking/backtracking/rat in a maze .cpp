/*
Rat in a Maze Problem - I
Medium Accuracy: 37.73% Submissions: 100k+ Points: 4
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
{1, 1, 0, 1},
{1, 1, 0, 0},
{0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
{1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/



#include <bits/stdc++.h> 


bool isSafe(int i,int j,int n,vector<vector<bool>>&visited,vector<vector<int>>&arr)
{
      if((i>=0 && i<n) && (j>=0 && j<n) && visited[i][j]==0 && arr[i][j]==1){
        return true;
    }
    return false;
}
void solve(vector < vector < int >> & arr, int n,vector<string>& ans,string output,vector<vector<bool>>& visited,int i,int j)
{
    if(i==n-1 and j==n-1) 
    {
        ans.push_back(output);
        return;
    }
    isited[i][j] =  1;
    //Down 
    int newX = i+1;
    int newY = j;
    if(isSafe(newX,newY,n,visited,arr)){
        output.push_back('D');
        solve(arr,n,ans,output,visited,newX,newY);
        output.pop_back();
    }
    
     //Left 
    newX = i;
    newY = j-1;
    if(isSafe(newX,newY,n,visited,arr)){
        output.push_back('L');
        solve(arr,n,ans,output,visited,newX,newY);
        output.pop_back();
    }
    
    //Right 
    newX = i;
    newY = j+1;
    if(isSafe(newX,newY,n,visited,arr)){
        output.push_back('R');
        solve(arr,n,ans,output,visited,newX,newY);
        output.pop_back();
    }
    
    //UP 
  newX = i-1;
newY = j;
    if(isSafe(newX,newY,n,visited,arr)){
        output.push_back('U');
        solve(arr,n,ans,output,visited,newX,newY);
        output.pop_back();
    }
    
    visited[i][j] =  0;
    return;
}
}
    
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    if(arr[0][0]==0) return ans;
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    int i=0;
    int j=0;
    string output="";
    solve(arr,n,ans,output,vis,i,j);
    return ans;
    
}
