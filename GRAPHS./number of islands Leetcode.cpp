/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.*/




class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i>=grid.size() || i<0 || j>= grid[0].size() || j<0)return;   //in case we go out of the grid;  base caseI
		
        if(grid[i][j]=='0')return;   // in case we already visited or it contains water; base CaseII
        
        grid[i][j]='0';   //we will make sure that we don't revisit the visited hence we will make it water after visited
        
        dfs(grid, i+1, j); //south call
        dfs(grid, i, j+1); //east call
        dfs(grid, i-1, j); //north call
        dfs(grid, i, j-1);  //west call
        
        
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0; i<grid.size(); i++){ 
          
          
          
          
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){// check only if grid[i][j] is land
                    dfs(grid, i, j);
                    count++;
                }
            }
        }    
        return count;
        
        
    }
};
