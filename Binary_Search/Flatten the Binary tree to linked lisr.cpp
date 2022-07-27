// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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
    void flatten(TreeNode* root) {
        
        if(root == NULL)
        {
            return;
        }
        
        vector<int>vec;
        preorder(root,vec);
        
        TreeNode*ptr=NULL;
        int i = 0;
        root->val = (vec[i]);
        i++;
        ptr=root;
        root->left = NULL;
        root->right = NULL;
        while(i != vec.size())
        {
            TreeNode * p= new TreeNode(vec[i]);
            p->left = NULL;
            p->right = NULL;
            ptr->right=p;
            ptr=ptr->right;
            i++;
        }
    }
    
    void preorder(TreeNode * root , vector<int>&vec)
    {
        if(root == NULL)
        {
            return;
        }
        vec.push_back(root->val);
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
};
