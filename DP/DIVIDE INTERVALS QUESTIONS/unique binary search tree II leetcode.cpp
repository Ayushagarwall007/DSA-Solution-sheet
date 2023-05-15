// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:


// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 8




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
vector<TreeNode*>solve(int start , int end)
{
    if(start>end)
    {
        return {NULL};
    }
    vector<TreeNode*>lChild,rChild,res;
    for(int i=start;i<=end;i++)
    {
        lChild=solve(start,i-1);
        rChild=solve(i+1,end);
    

    for(auto l:lChild)
    {
        for(auto r:rChild)
        {
            TreeNode* node=new TreeNode(i);
            node->left=l;
            node->right=r;
            res.push_back(node);
        }
        
    }
}
return res;
}
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);

    }
};