// 1339. Maximum Product of Splitted Binary Tree
// Medium

// 1454

// 64

// Add to List

// Share
// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// Example 2:


// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

// Constraints:

// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104



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
     int tsum=0;
    //find the total sum of the tree
    void in(TreeNode* root)
    {
        if(!root)
            return;
        in(root->left);
        tsum+=root->val;
        in(root->right);
    }
     long long msum=0;
    int get_prod(TreeNode* root)
    {
        if(!root)
            return 0;
        //if leaf node then return its's value
        if(!root->left&&!root->right)
            return root->val;
        //get sum of left subtree
        int ls=get_prod(root->left);
        //get sum pf roght subtree
        int rs=get_prod(root->right);
        //get the 2 subtrees by removing ls and rs one by one from the total sum and calculate the maximum product 
        msum=max(msum,max((long long)(tsum-ls)*ls,(long long)(tsum-rs)*rs));
        return root->val+ls+rs;
    }
    
    int maxProduct(TreeNode* root) {
        in(root);
        get_prod(root);
        return msum%(int)(1e9+7);
    }
};


