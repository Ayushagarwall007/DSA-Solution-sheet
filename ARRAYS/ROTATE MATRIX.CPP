  // WRITE A CPP PROGRAM TO ROTATE THE MATRIX BY 90 DEGREE
// to do so here first we take the transpose of the matrix and then reverse each row of the matrix to rotate the matrix by 90 degree


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }    }

};
