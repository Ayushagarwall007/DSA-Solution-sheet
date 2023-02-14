// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

 

// Example 1:


// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
// Example 2:

// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]
 

// Constraints:

// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.



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

    void deleteNode(TreeNode* &root, unordered_set<int> &st)
    {
        if(root==NULL)
        return;
        if(st.count(root->val))
        {
            root = NULL;
            return;
        }
    }

    void traverse(TreeNode* &root, unordered_set<int> &st, vector<TreeNode*> &res)
    {
        if(root==NULL) return;

        traverse(root->left, st, res);
        traverse(root->right, st, res);

        if(st.count(root->val))
        {
            if(root->left and !st.count(root->left->val))
            {
                res.push_back(root->left);
            }
            if(root->right and !st.count(root->right->val))
            {
                res.push_back(root->right);
            }
            deleteNode(root, st);
        }
    }

public:

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> st(to_delete.begin(), to_delete.end()); // set created to know in O(1) time whether to deletr or current node
        vector<TreeNode*> res;

        traverse(root, st, res);
        deleteNode(root, st); 

        if(root)
        res.push_back(root); // finally adding root node to cover remaing nodes above the nodes to be deleted.

        return res;
    }

};
