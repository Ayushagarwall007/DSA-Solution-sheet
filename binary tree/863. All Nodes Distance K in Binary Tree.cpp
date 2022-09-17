// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int n;
    vector<int> ans;
    TreeNode* head;                     // Temporary node to store root node of the tree
    map<TreeNode*,TreeNode*> mp;       // This map is to store each node's parent(for root parent is NULL)
    map<TreeNode*,int> vis;            // This map is needed to keep track of not recursively going around the same node multiple times
    
    void solve(TreeNode* root,int k)
    {
        if(!root)return;               // If visited, no need to go further or check
        if(vis[root]==1)return;
        vis[root]=1;
        if(k==n){ans.push_back(root->val);return;}
        solve(root->left,k+1);         // From a node You can go to three directions: left child node
        solve(root->right,k+1);        //                                             right child node
        solve(mp[root],k+1);           //                                             parent node
    }
    void dfs(TreeNode* root,TreeNode* target,TreeNode* parent)
    {
        if(!root)return;
        mp[root]=parent;
        if(root==target)               // Just finding target node with this function, and when encountered, called solve function
        {
            solve(root,0);
            return;
        }
        dfs(root->left,target,root);
        dfs(root->right,target,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        n=k;
        head=root;
        dfs(root,target,NULL);
        return ans;
    }
};



