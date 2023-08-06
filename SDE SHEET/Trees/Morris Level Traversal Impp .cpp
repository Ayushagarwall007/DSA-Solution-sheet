// 114. Flatten Binary Tree to Linked List
// Medium
// 11.1K
// 528
// Companies
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

// Example 1:


// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100



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


//  morris level traversal
//  phle ekk baar left jaoo phir right jaate rahoo...
//  phir last waale right node kaa right curr ka right banaa doo...
//  or current kaa right curr ke left banaa do...
//  aab curr=curr->right kaar do


class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left)
            {
                TreeNode* pred=curr->left;
                while(pred->right)
                {
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;

            }
                curr=curr->right;
        }
        curr=root;
        while(curr!=NULL)
        {
            curr->left=NULL;
            curr=curr->right;
        }
    }
};
