// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100
 

// Follow up: Could you solve it both recursively and iteratively?




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
    bool checkIfMirror(TreeNode* root1 , TreeNode* root2)
    {
        if(root1==NULL and root2!=NULL)return false;
        if(root1==NULL and root2==NULL)return true;
        if(root1!=NULL and root2==NULL)return false;
        if(root1->val!=root2->val)return false;
        else
        {
            int opt1=checkIfMirror(root1->left,root2->right);
            int opt2=checkIfMirror(root1->right,root2->left);
            return opt1 and opt2;
        }
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return  true;
       bool ans=  checkIfMirror(root->left,root->right);
        return ans;
    }
};
