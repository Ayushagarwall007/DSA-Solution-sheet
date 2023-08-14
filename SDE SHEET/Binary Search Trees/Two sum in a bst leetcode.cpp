// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -104 <= Node.val <= 104
// root is guaranteed to be a valid binary search tree.
// -105 <= k <= 105




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
void inorder(TreeNode* root,vector<int>&v)
{
    if(root==NULL)return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            int sum=v[i]+v[j];
            if(sum==k)
            {
                return true;
                break;
            }
            if(sum>k)
            {
                j--;
            }
            if(sum<k)
            {
                i++;
            }
        }
        return false;
    }
};
