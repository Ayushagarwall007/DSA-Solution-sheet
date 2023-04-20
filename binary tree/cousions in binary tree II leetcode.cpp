// 2641. Cousins in Binary Tree II
// User Accepted:3941
// User Tried:4996
// Total Accepted:4071
// Total Submissions:7208
// Difficulty:Medium
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.

 

// Example 1:


// Input: root = [5,4,9,1,10,null,7]
// Output: [0,0,0,7,7,null,11]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 5 does not have any cousins so its sum is 0.
// - Node with value 4 does not have any cousins so its sum is 0.
// - Node with value 9 does not have any cousins so its sum is 0.
// - Node with value 1 has a cousin with value 7 so its sum is 7.
// - Node with value 10 has a cousin with value 7 so its sum is 7.
// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
// Example 2:


// Input: root = [3,1,2]
// Output: [0,0,0]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 3 does not have any cousins so its sum is 0.
// - Node with value 1 does not have any cousins so its sum is 0.
// - Node with value 2 does not have any cousins so its sum is 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
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
 // */
// in this question phle humne saare level ke total sum ekk  map mai store kaar liye the..
//     abb cousions nikalne ki baari to ekk node ek atmax 2 child ho sakte hai to abb kya karenge ki ekk child ko parent ke threw dusre
//     child kaa acknowledge denge ie sameParentSibling or humm usss level ke total sum se uss node ki value or sibling ki value minuskaar denge
//     aiaa hum haar child ke liye karenge
    
class Solution {
public:
    unordered_map<int,int>levelSum;
    
    void dfs(TreeNode* root,int level)
    {
        if(root==NULL)return ;
        levelSum[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    void solve(TreeNode * root,int sameParentSiblingSum,int level)
    {
        if(root==NULL)return ;
        int leftChild=root->left==NULL?0:root->left->val;
        int rightChild=root->right==NULL?0:root->right->val;
        solve(root->left,rightChild,level+1);
        solve(root->right,leftChild,level+1);
        root->val=levelSum[level]-root->val-sameParentSiblingSum;
        
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root,0);
        solve(root,0,0);
        return root;
    }
};
