// 1315. Sum of Nodes with Even-Valued Grandparent
// Medium
// 2.1K
// 63
// Companies
// Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

// A grandparent of a node is the parent of its parent if it exists.

 

// Example 1:


// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18
// Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
// Example 2:


// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 100





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
//  We need to keep track of three node in order to solve this problem that is current, parent and grandParent. While calling the dfs function we don't know the parent and grandParent of the current node, so we pass NULL. In every step of the dfs the current will take current->left or current->right, parent will take current and grandParent will take parent. We also have to check whether we hit a grandParent whose value is a multiple of 2. If that turns out to be true in some dfs call then we need to add the value of that node in our sum variable.
class Solution {
public:
    int sum=0;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,NULL,NULL);
        return sum;
    }
    void dfs(TreeNode* root,TreeNode* parent,TreeNode* Grandparent)
    {
        if(!root) return ;
        if(Grandparent!=NULL and Grandparent->val%2==0)sum+=root->val;
        dfs(root->left,root,parent);
        dfs(root->right,root,parent);
    }
};
