// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int top=0,right=m-1,bottom=n-1,left=0;
        while(top<=bottom && left<=right){
            
            // phli roww ko print kaaro or starting row ko inc kaar do
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            // aab last column koo print kaar doo or last column ko decrease kaar do 
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            // aab last ko print kaar do or last row ko increase kaar do
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            // aab phle column ko print kaar do or phli coulmn koo increse kaar do
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};
