// Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

// For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

// Example 1:



// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3 
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
// Example 2:

// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1
// Example 3:

// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1
 

// Constraints:

// 1 <= rows, cols <= 50
// rows == pizza.length
// cols == pizza[i].length
// 1 <= k <= 10
// pizza consists of characters 'A' and '.' only.




// class Solution {
// public:
//     long long MOD = 1000000007;
//     bool isValid(vector<string>&pizza, int startRow, int endRow, int startCol, int endCol)
//     {
//         for (int i = startRow; i <= endRow; i++)
//         {
//             for (int j = startCol; j <= endCol; j++)
//             {
//                 if (pizza[i][j] == 'A') return true;
//             }
//         }
//         return false;
//     }
//     int solve(vector<string>&pizza, int startRow, int startCol, int cutsLeft)
//     {
//         int m = pizza.size(), n = pizza[0].size();
// 		//endRow = m - 1 and endCol = n - 1 always [so no need to use those parameters in recursive call]
//         if (cutsLeft == 0) return 1;
//         //============================================================================================
//         long long ans = 0;
//         //we are making a cut below the rowIndex = 'row'
//         for (int row = startRow; row < m - 1; row++) 
//         {
//             bool upperHalfValid = isValid(pizza, startRow, row, startCol, n - 1);
//             bool lowerHalfValid = isValid(pizza, row + 1, m - 1, startCol, n - 1);
//             if (upperHalfValid && lowerHalfValid)  //upperHalf will be given away
//             {
//                 int nextWays =  (solve(pizza, row + 1, startCol, cutsLeft - 1)); //lowerHalf
//                 ans = (ans + nextWays) % MOD;
//             }
//         }
//         //======================================================================================
//          //we are making a cut towards the right of colIndex = 'col'
//         for (int col = startCol; col < n - 1; col++)
//         {
//             bool leftHalfValid = isValid(pizza, startRow, m - 1, startCol, col); 
//             bool rightHalfValid = isValid(pizza, startRow, m - 1, col + 1, n - 1);
//             if (leftHalfValid && rightHalfValid) //leftHalf will be given away
//             {
//                 int nextWays = solve(pizza, startRow, col + 1, cutsLeft - 1); //rightHalf
//                 ans = (ans + nextWays) % MOD;
//             }
//         }
//         //===============================================================================================
//         return (int)ans;
//     }
//     int ways(vector<string>& pizza, int k)
//     {
//         int m = pizza.size(), n = pizza[0].size();
//         int ans = solve(pizza, 0, 0, k - 1);
//         return ans;
        
//     }
// };



class Solution {
public:
    long long MOD = 1000000007;
    bool isValid(vector<string>&pizza, int startRow, int endRow, int startCol, int endCol)
    {
        for (int i = startRow; i <= endRow; i++)
        {
            for (int j = startCol; j <= endCol; j++)
            {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int solve(vector<string>&pizza, vector<vector<vector<int>>>&dp, int startRow, int startCol, int cutsLeft)
    {
        int m = pizza.size(), n = pizza[0].size();
        if (cutsLeft == 0) return 1;
        
        if (dp[startRow][startCol][cutsLeft] != -1) return dp[startRow][startCol][cutsLeft];
        //============================================================================================
        long long ans = 0;
        //we are making a cut below the rowIndex = 'row'
        for (int row = startRow; row < m - 1; row++) 
        {
            bool upperHalfValid = isValid(pizza, startRow, row, startCol, n - 1);
            bool lowerHalfValid = isValid(pizza, row + 1, m - 1, startCol, n - 1);
            if (upperHalfValid && lowerHalfValid)  //upperHalf will be given away
            {
                int nextWays =  (solve(pizza, dp, row + 1, startCol, cutsLeft - 1)); //lowerHalf
                ans = (ans + nextWays) % MOD;
            }
        }
        //======================================================================================
         //we are making a cut towards the right of colIndex = 'col'
        for (int col = startCol; col < n - 1; col++)
        {
            bool leftHalfValid = isValid(pizza, startRow, m - 1, startCol, col); 
            bool rightHalfValid = isValid(pizza, startRow, m - 1, col + 1, n - 1);
            if (leftHalfValid && rightHalfValid) //leftHalf will be given away
            {
                int nextWays = solve(pizza, dp, startRow, col + 1, cutsLeft - 1); //rightHalf
                ans = (ans + nextWays) % MOD;
            }
        }
        //===============================================================================================
        return dp[startRow][startCol][cutsLeft] = (int)ans;
    }
    int ways(vector<string>& pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        vector dp(m, vector(n, vector<int>(k, -1)));
        int ans = solve(pizza, dp, 0, 0, k - 1);
        return ans;
        
    }
};
