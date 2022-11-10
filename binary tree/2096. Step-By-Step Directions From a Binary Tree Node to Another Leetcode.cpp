// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:


// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:


// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue




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
//  steps :-
// 1-> find the lca of both the nodes
// 2-> find the sammalest path from that lca node to both the node
// 3-> concatenate both the path
class Solution {
public:
    TreeNode* lca(TreeNode* root,int p,int q)
    {
        if(root==NULL or root->val==p or root->val==q) return root;
        TreeNode *left=lca(root->left,p,q);
        TreeNode * right=lca(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else // if we find both the value from the left and the right then we find the node;
        return root;
    }

    bool findPath(TreeNode *root, int valueToBeFound,string &str) {
        if (root == nullptr) return false;
        if (root->val == valueToBeFound) {
            return true;
        }
        bool l = findPath(root->left, valueToBeFound,str);
        bool r = findPath(root->right, valueToBeFound,str);
        if (l) {
            str = "L" + str;
        } else if (r) {
            str = "R" + str;
        }
        return (l || r);
    }
   string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        string p1, p2;
        findPath(root, startValue, p1);
        findPath(root, destValue, p2);
        for(auto &c : p1) c = 'U';
        return p1 + p2;
    }
};
