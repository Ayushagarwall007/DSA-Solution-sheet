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
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true


class Solution {
public:
	//In this approach we don't have a different BS fucntion.
	//We will manipulate pointers in one loop only
	
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//Taking size of row and columns
        int totalRows = matrix.size(), totalCols = matrix[0].size();
		
		//Initializing starting points for our search, which will be top right corner element, why ?
		//Ans: As you can see in the given example, top right corner element will always be greater
		//than its row elements and smallest among its column elements.
		
		//So we choose this element as our starting point and check if our target exists or not.
		
        int row = 0, col = totalCols - 1;
		
		//The condition here will be for row will always be lesser than total rows
		//And as we are starting from the right most column we have to traverse to left side, so
		//col should be greater than or equal to 0.
		
        while(row < totalRows && col >= 0) {
		
			//Checking if the element is target, then simply return
            if(matrix[row][col] == target) return true;
			
			//Checking if element is greater, now this means as our target is lesser than this element
			//and we know for a fact that all the row elements for this element will be smaller 
			//so, we decrease 1 column as this was the largest among its rows.
            else if(matrix[row][col] > target) {
                col--;
            }
			
			//Checking if element is smaller, now this means our target is greater than this element, and
			//we know that our element is smallest among its column, so we increase its row by 1
            else {
                row++;
            }
        }
		
		//if we don't find out target, simply return false
        return false;
    }
};
