// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:



// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
// Example 2:



// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
// Example 3:

// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 4 * 104].
// -4 * 104 <= Node.val <= 4 * 104




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
    
    class info
    {
        public:
        int maxi,mini;
        bool isBst;
        int sum;
    };
     
    info solve(TreeNode * root,int & ans)
    {
        if(root==NULL)return {INT_MIN,INT_MAX,true,0};
        
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        
        info currNode;
        currNode.maxi=max(root->val,right.maxi);
        currNode.mini=min(root->val,left.mini);
        
        currNode.sum=left.sum + right.sum + root->val; 
        
        if(left.isBst && right.isBst && (root->val> left.maxi && root->val < right.mini)){
        currNode.isBst = true;
            currNode.sum = left.sum + right.sum + root->val;
        }
        else {
        currNode.isBst  = false;
        }
        
        
        if(currNode.isBst)ans = max(ans,currNode.sum);
        return currNode;
    }
    
    
    int maxSumBST(TreeNode* root) {
        int sum=0;
        info t=solve(root,sum);
        return sum;
    }
};
