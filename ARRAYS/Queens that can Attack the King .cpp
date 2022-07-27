// On an 8x8 chessboard, there can be multiple Black Queens and one White King.

// Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the position of 
// the White King, return the coordinates of all the queens (in any order) that can attack the King.

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
// making all the positions of the queen as 1 to check for its y
        vector<vector<int>> board(8,vector<int>(8,0));
        for (auto v:queens) board[v[0]][v[1]]=1; //.................................................................................    
        for (int i=king[0];i<8;i++) {  // checking for the downward movement in the rows
            if (board[i][king[1]]==1) {
                ans.push_back({i,king[1]});
                break;
            }
        }
  //........................................................................................      
        for (int i=king[0];i>=0;i--) { // checking for the upward movement in the rows
            if (board[i][king[1]]==1) {
                ans.push_back({i,king[1]});
                break;
            }
        }
//........................................................................................ 
        for (int i=king[1];i<8;i++) {  // checking for the right movement in the column
            if (board[king[0]][i]==1) {
                ans.push_back({king[0],i});
                break;
            }
        }
//........................................................................................ 
        for (int i=king[1];i>=0;i--) {// checking for the left movement in the column
            if (board[king[0]][i]==1) {
                ans.push_back({king[0],i});
                break;
            }
        }
//..........................................................................................
        int i=king[0],j=king[1];// checking for the right downward diaginal 
        while (i<8&&j<8) {
            if (board[i][j]==1) {
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
//........................................................................................ 
        i=king[0],j=king[1];// checking for the upward left diaginal
        while (i>=0&&j>=0) {
            if (board[i][j]==1) {
                ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
//........................................................................................ 
        i=king[0],j=king[1]; //checking for the right upper diagonal
        while (i>=0&&j<8) {
            if (board[i][j]==1) {
                ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
//........................................................................................
        i=king[0],j=king[1]; //  checking for the left down diagonal
        while (i<8&&j>=0) {
            if (board[i][j]==1) {
                ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};
