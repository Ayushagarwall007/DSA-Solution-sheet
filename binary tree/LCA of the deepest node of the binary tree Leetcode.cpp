// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

// Recall that:

// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest leaf-nodes of the tree.
// Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree, and it's the lca of itself.
// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

// Constraints:

// The number of nodes in the tree will be in the range [1, 1000].
// 0 <= Node.val <= 1000
// The values of the nodes in the tree are unique.
 




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
TreeNode* lca(TreeNode* root,TreeNode*left,TreeNode* right)
{
    if(!root)return NULL;
    if(root==left)return left;
    if(root==right)return right;
    TreeNode* l=lca(root->left,left,right);
    TreeNode* r=lca(root->right,left,right);
    if(l&&r)return root;
    return r?r:l;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root or (!root->left and !root->right))return root;
        vector<TreeNode*>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<TreeNode*>sub;
            while(len--)
            {
                TreeNode* curr=q.front();
                q.pop();
                sub.push_back(curr);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                
            }
            v=sub;
        }
        if(v.size()==1)return v[0];
        TreeNode*left=v.front();
        TreeNode* right=v.back();
        v.clear();
        TreeNode* node=lca(root,left,right);
        return node;
    }
};
