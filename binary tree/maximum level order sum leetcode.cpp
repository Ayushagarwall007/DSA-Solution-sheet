// 1161. Maximum Level Sum of a Binary Tree
// Medium
// 1.7K
// 65
// Companies
// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

// Example 1:


// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105




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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=1;
        int maxSum=INT_MIN;
        int level=1;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                sum+=n->val;
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            if(maxSum<sum)
            {
                ans=level;
                maxSum=sum;
                
            }
            level++;
            
        }
        return ans;

    }
};
