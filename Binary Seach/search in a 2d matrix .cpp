// // level 1 problem leetcode
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row=matrix.size();
        int col= matrix[0].size();
        int start =0;
        int end= row*col-1;
        int mid= start+(end-start)/2;
        while(start<=end)
        {
            int element=matrix[mid/col][mid%col];
            if(element==target)
            {
                return 1;
            }
            if(element<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            mid=start+(end-start)/2;
            
        }
        return 0;
    }
};

//*************************************************************************************************************************************************************

// level 2  search in a 2D matrix II leetcode
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;
        while(rowIndex<row&&colIndex>=0)
        {
            int element=matrix[rowIndex][colIndex];
            if(element==target)
                return 1;
            else if(element < target)
            {
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
};

 
