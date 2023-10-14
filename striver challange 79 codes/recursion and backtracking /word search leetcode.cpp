// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?


class Solution {
public:
bool dfs(vector<vector<char>>&board,int i , int j , int ind,string &word)
{
    if(ind==word.size())return true;
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[ind])return false;
    board[i][j]='-';
    bool ans=dfs(board,i+1,j,ind+1,word) or
             dfs(board,i-1,j,ind+1,word) or
             dfs(board,i,j+1,ind+1,word) or
             dfs(board,i,j-1,ind+1,word);
    board[i][j]=word[ind];

    return ans;
              
}
    bool exist(vector<vector<char>>& board, string word) {
        // int n=board.size();
        // int m=board[0].size();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                   bool ans= dfs(board,i,j,0,word);
                   if(ans==true)return true;
                }
            }
        }
        return false;
    }
};


