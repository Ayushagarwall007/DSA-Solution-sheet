// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.


// // START from the 0's at the boundry and mark them all the connected zeroes as not converted and al last make all the CanConverted 0's to X
// class Solution {
// private:
// int delrows[4]={-1,0,+1,0};
//     int delCols[4]={0,+1,0,-1};
// void dfs(int row,int column,vector<vector<int>> &vis , vector<vector<char>> board)
// {
//      vis[row][column]=1;
//     int n=board.size();
//     int m=board[0].size();
   
//     // now check for the bottom, left , right and up of that particular element at the boundry
//     for(int i=0;i<4;i++)
//     {
//         int newrow=row+delrows[i];
//         int newCols=column+delCols[i];
//         if(!vis[newCols][newCols] and newrow>=0 and newrow<n and newCols>=0 and newCols<m and board[newCols][newrow]=='O')
//         {
//             dfs(newrow,newCols,vis,board);
//         }
        
//     }

// }

// public:
//     void solve(vector<vector<char>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         vector<vector<int>> vis(n,vector<int>(m,0));

//         // treversing the boundries for the check of the '0'
//         // First row and the last row
//         for(int i=0;i<m;i++)
//         {
//             if(!vis[0][i] and board[0][i]=='O') dfs(0,i,vis,board);
//             if(!vis[n-1][i] and board[n-1][i]=='O') dfs(n-1,i,vis,board);
//         }

//         // first and the last column
//         for(int i=0;i<n;i++)
//         {
//             if(!vis[i][0] and board[i][0]=='O') dfs(i,0,vis,board);
//             if(!vis[i][m-1] and board[m-1][0]=='O') dfs(i,m-1,vis,board);
//         }


//         for(int i=0;i<n;i++)
//         {
//         for(int j=0;j<m;j++)
//         {
//             cout<<vis[i][j]<<" ";
//         }
//             cout<<endl;
//          }



            
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(!vis[i][j] and board[i][j]=='O') board[i][j]='X';
//             }
//         }

       
        
//     }
// };


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        //checking the borders for O's and if it has any connecting O's and we are making them as 1
        //to keep a note that we have visited them, later we'll convert these 1's back to O's
        
        //vertical borders
        for(int i=0; i<rows; i++)  {
            if(board[i][0]=='O') 
                dfs(board, i, 0);
            if(board[i][cols-1]=='O')
                dfs(board, i, cols-1);     
        }
        //horizontal borders
        for(int j=1; j<cols-1; j++) {
            if(board[0][j]=='O') 
                dfs(board, 0, j);
            if(board[rows-1][j]=='O')
                dfs(board, rows-1, j);
        }
        //traversing the matrix (except for the border)
        for(int i=1;i<rows-1;i++) {
            for(int j=1; j<cols-1; j++) {
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        //traversing the entire matrix & changing the border and its connected O's from 1 to 0
        for(int i=0;i<rows;i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j]=='1') board[i][j]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i<0||j<0||i>board.size()-1||j>board[0].size()-1||board[i][j]=='X'||board[i][j]=='1') return;
        if(board[i][j]=='O') {
            board[i][j]='1';
            dfs(board, i+1, j); //down
            dfs(board, i-1, j); //up
            dfs(board, i, j+1); //right
            dfs(board, i, j-1); //left
        }
    }
};
