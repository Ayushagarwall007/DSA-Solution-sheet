// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 300
// -109 <= matrix[i][j] <= 109
// All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
// 1 <= k <= n2
 

// Follow up:

// Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
// Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.


// BF: SORTING
// TC: O(n^2 log(n^2)), SC: O(n^2)

class Solution {
public:
   int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                ans.push_back(matrix[i][j]);
            }
        }
    
    sort(ans.begin(), ans.end());
       
    return ans[k-1];
	}
};



// BETTER: Priority Queue (Max heap)
// TC: O(n^2 logK), SC: O(K)

class Solution {
public:
   int kthSmallest(vector<vector<int>>& matrix, int k)
	{   
       int n=matrix.size();
		priority_queue<int> q;
       
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            q.push(matrix[i][j]);
            
            if (q.size() > k){
                 q.pop();
            }
        }
    }
    
    return q.top();
	}
};


// OPTIMAL: Binary Seach
// TC: O(N log(N^2)), SC: O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int l=matrix[0][0], r=matrix[n-1][n-1], mid;
        
        while(l<r){
            
            mid=l+(r-l)/2;
            int cnt=0, j=n-1;
            
            // For each row count the elements that are smaller than mid
            for(int i=0;i<n;i++){
                
                while(j>=0&&matrix[i][j]>mid)
                    j--;
                
                cnt+=j+1;
            }
            
            if(cnt<k)
                l=mid+1;
            else
                r=mid;
        }
        
        return l;
    }
};
