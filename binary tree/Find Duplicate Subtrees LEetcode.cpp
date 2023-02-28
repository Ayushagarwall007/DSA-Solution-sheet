// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.

 

// Example 1:


// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]
// Example 2:


// Input: root = [2,1,1]
// Output: [[1]]
// Example 3:


// Input: root = [2,2,2,3,null,3,null]
// Output: [[2,3],[3]]
 

// Constraints:

// The number of the nodes in the tree will be in the range [1, 5000]
// -200 <= Node.val <= 200






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
string inorder(TreeNode*root ,unordered_map<string,int>&mp,vector<TreeNode*>&res)
{
    if(!root)return "";
    string str="(";
    str+=inorder(root->left,mp,res);
    str+=to_string(root->val);
    str+=inorder(root->right,mp,res);
    str+=")";

    cout<<str<<" ";
    if(mp[str]==1)res.push_back(root);
    mp[str]++;
    return str;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // if(root==NULL)return {};
        vector<TreeNode*>res;
        unordered_map<string,int>mp;
        inorder(root,mp,res);
        return res;
    }
};
