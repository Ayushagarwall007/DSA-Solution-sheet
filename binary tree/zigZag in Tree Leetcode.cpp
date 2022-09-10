// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int>> ();
        
        vector<vector<int>> result;
        queue<TreeNode* > nodeQueue;
        nodeQueue.push(root);
        
        bool leftToRight=true;
        
        while(!nodeQueue.empty())
        {
            int size=nodeQueue.size();
            vector<int> row(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode * node=nodeQueue.front();
                nodeQueue.pop();
                
                int index=(leftToRight)?i:(size-i-1);
                row[index]=node->val;
                if(node->left)nodeQueue.push(node->left);
                if(node->right)nodeQueue.push(node->right);
            }
            leftToRight=!leftToRight;
            result.push_back(row);
        }
        return result;
        
        
    }    
};
