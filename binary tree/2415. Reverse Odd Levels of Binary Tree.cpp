// Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

// For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
// Return the root of the reversed tree.

// A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

// The level of a node is the number of edges along the path between it and the root node.

 

// Example 1:


// Input: root = [2,3,5,8,13,21,34]
// Output: [2,5,3,8,13,21,34]
// Explanation: 
// The tree has only one odd level.
// The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
// Example 2:


// Input: root = [7,13,11]
// Output: [7,11,13]
// Explanation: 
// The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
// Example 3:

// Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
// Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
// Explanation: 
// The odd levels have non-zero values.
// The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
// The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 214].
// 0 <= Node.val <= 105
// root is a perfect binary tree.




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
    vector<int> traverse;
    
    TreeNode* reverseOddLevels(TreeNode* root) {
            bool oddLevel=false;
        
        auto Root=root;
        queue<TreeNode*> q;
        
        q.push({root});
        
        while(!q.empty())
        {
            int cnt=q.size();
            vector<int> temp;
            while(cnt--)
            {
                auto node= q.front();
                q.pop();
                
            temp.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
                
                if(oddLevel)
                {
                    reverse(temp.begin(),temp.end());
                    
                    for(auto a:temp)traverse.push_back(a);
                    oddLevel=false;
                    
                }
                else
                {
                    for(auto a: temp)traverse.push_back(a);
                    oddLevel=true;
                }
        }
        
      queue<TreeNode*> Q;
        Q.push({Root});
        int j = 1;
        
        while(Q.size() && j < traverse.size()) {
            int cnt = Q.size();
            while(cnt--) {
                auto node = Q.front();
                Q.pop();
                
                if(j < traverse.size()) {
                    node->left = new TreeNode(traverse[j++]);
                }
                if(j < traverse.size()) {
                    node->right = new TreeNode(traverse[j++]);
                }
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
        }
        return Root;
    }
};
