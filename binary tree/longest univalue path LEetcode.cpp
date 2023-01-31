// Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

// The length of the path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [5,4,5,1,1,null,5]
// Output: 2
// Explanation: The shown image shows that the longest path of the same value (i.e. 5).
// Example 2:


// Input: root = [1,4,5,4,4,null,5]
// Output: 2
// Explanation: The shown image shows that the longest path of the same value (i.e. 4).
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
// The depth of the tree will not exceed 1000.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxLen=0;
        DFS(root,maxLen);
        return maxLen;
    }

    int DFS(TreeNode* root,int &maxLen)
    {
        if(!root)return 0;
        int left=DFS(root->left,maxLen);
        int right=DFS(root->right,maxLen);
        if(!root->left or root->left->val!=root->val)left= 0;
        if(!root->right or root->right->val!=root->val)right= 0;
        maxLen=max(maxLen,left+right);
        return max(left,right)+1;

    }
};
