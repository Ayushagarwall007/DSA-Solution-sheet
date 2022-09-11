Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



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
    vector<vector<int>> ans;
    
    void solve(TreeNode* root, int targetSum,vector<int> level,int sum)
    {
        if(root==NULL)return;
        
        sum+=root->val;
        level.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL and sum== targetSum)
        {
            ans.push_back(level);
            return;
        }
        
        solve(root->left,targetSum,level,sum);
            solve(root->right,targetSum,level,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<int> level;
        
        solve(root,targetSum,level,0);
        return ans;
    }
};
