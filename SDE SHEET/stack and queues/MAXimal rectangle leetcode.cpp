// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.




// Approach
// The solution uses the concept of histogram where the heights of each column are taken as bars of the histogram. Then, the problem is reduced to finding the largest rectangle area in the histogram.

// The code first defines two helper functions nextSmaller() and prevSmaller() that return the indices of the next smaller and previous smaller element to each element of a given array. These functions use a stack to store the indices of the elements in a decreasing order of their values. The top of the stack always stores the index of the next smaller or previous smaller element.

// Then, the maxAreaHistogram() function takes an array and returns the maximum area of the rectangle that can be formed using the histogram of the heights of the bars of the histogram. It uses the nextSmaller() and prevSmaller() functions to calculate the next and previous smaller elements' indices for each element in the array and then calculates the maximum area of the rectangle using the formula area = length * width, where length is the height of the current element, and width is the distance between the next smaller and previous smaller element indices.

// Finally, the maximalRectangle() function takes the binary matrix as input, converts it into an array of integers, and calculates the maximum area of the rectangle by iterating over each row of the matrix and updating the array of heights for each row. The maximum area is returned as the output.

// Overall, the code is an implementation of the histogram-based approach to find the maximal rectangle area in a binary matrix.

// Complexity
// Time complexity:
// O(m*n) where m and n are the dimensions of the input matrix.

// Space complexity:
// O(m*n)

// Code
class Solution {
private:
    vector<int> nextSmaller(vector<int> &arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int maxAreaHistogram(vector<int> &arr){
        int n = arr.size();
        vector<int> next(n);
        vector<int> prev(n);
        next = nextSmaller(arr,n);
        prev = prevSmaller(arr,n);
        int area = 0;
        for(int i=0;i<arr.size();i++){
            int length = arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int width = next[i]-prev[i]-1;
            area = max(area,(length*width));
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> mat;
        for(int i=0;i<matrix.size();i++){
            vector<int> v;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    v.push_back(1);
                }
                else{
                    v.push_back(0);
                }
            }
            mat.push_back(v);
        }
        int n = mat.size();
        int area = maxAreaHistogram(mat[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    mat[i][j]+=mat[i-1][j];
                }
            }
            area=max(area,maxAreaHistogram(mat[i]));
        }
        return area;
    }
};
