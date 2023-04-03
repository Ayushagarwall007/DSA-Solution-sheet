// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

 

// Example 1:


// Input: arr = [6,2,4]
// Output: 32
// Explanation: There are two possible trees shown.
// The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
// Example 2:


// Input: arr = [4,11]
// Output: 44
 

// Constraints:

// 2 <= arr.length <= 40
// 1 <= arr[i] <= 15
// It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).




// class Solution {
// public:
// pair<int, int> treeSum(vector<int>& arr, int st, int end) {
// 	// Base case when there is a leaf node.
// 	if (st == end) {
// 		return {arr[st], 0};
// 	}

// 	/*
// 	   Create a two variables minSum to store the minimum sum of non-leaf nodes
// 	   and maxLeaf to store the maximum of leaf node
// 	*/
// 	int minSum = INT_MAX, maxLeaf = INT_MIN;

// 	// Split the array at the every ith position.
// 	for (int i = st; i < end; i++) {
// 		// Calling on the left subarary.
// 		pair<int, int> left = treeSum(arr, st, i);

// 		// Calling on the right subarray.
// 		pair<int, int> right = treeSum(arr, i + 1, end);

// 		minSum = min(minSum, left.second + right.second + (left.first * right.first));
// 		maxLeaf = max(left.first, right.first);
// 	}
// 	return {maxLeaf, minSum};
// }

//     int mctFromLeafValues(vector<int>& arr) {
//         return treeSum(arr,0,arr.size()-1).second;
//     }
// };
// `
/*
Return the pair of integers
The first one will be the max value of the leaf node in that subtree
The second one will be the minimum value of the sum of non-leaf nodes from left to right subtrees.*/
// dp on interval division patterns questions


class Solution
{
	public:
pair<int, int> treeSum(vector<int>& arr, int st, int end , vector<vector<pair<int, int>>>& dp) {
	// Base case to check for leaf node.
	if (st == end) {
		return {arr[st], 0};
	}

	// To check whether we have already calculated the solution of the subproblem.
	if (dp[st][end].second != -1) {
		return dp[st][end];
	}

	/*
	   Create a two variables minSum to store the minimum sum of non-leaf nodes
	   and maxLeaf to store the maximum of leaf node
	*/
	int minSum = INT_MAX, maxLeaf = INT_MIN;

	// Split the array at the every ith position.
	for (int i = st; i < end; i++) {
		// Calling on the left subarary.
		pair<int, int> left = treeSum(arr, st, i , dp);

		// Calling on the right subarray.
		pair<int, int> right = treeSum(arr, i + 1, end , dp);
		minSum = min(minSum, left.second + right.second + (left.first * right.first));
		maxLeaf = max(left.first, right.first);
	}

	// Storing the answer in the dp table before retuning the answer.
	dp[st][end] = {maxLeaf, minSum};
	return dp[st][end];
}
int mctFromLeafValues(vector<int>& arr) {
	/*
	   Create a 2d Array of pairs 'DP' intialise with zero. The first one will be the
	   max value of the leaf node in that subtree The second one will be the minimum
	   value of the sum of non-leaf nodes from left to right subtrees.
	*/
	vector<vector<pair<int, int>>> dp = vector<vector<pair<int, int>>>(arr.size(), vector<pair<int, int>>(arr.size(), {INT_MIN, -1}));

	return treeSum(arr, 0, arr.size() - 1 , dp).second;
}
};
