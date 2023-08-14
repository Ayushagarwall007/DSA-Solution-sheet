// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

// Example 1:


// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
// Example 2:

// Input: preorder = [1,3]
// Output: [1,null,3]
 

// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 1000
// All the values of preorder are unique.



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
unordered_map<int,int>inMap;
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int>in=pre;
        sort(in.begin(),in.end());
        int n=pre.size();
        for(int i=0;i<n;i++)
        {
            inMap[in[i]]=i;
        }
        int preFirst=0;
        return construct(pre,in,preFirst,0,n-1);
    }

    TreeNode* construct(vector<int>&pre,vector<int>&in,int &preFirst,int left,int right)
    {
        if(left>right)return NULL;
        TreeNode* root=new TreeNode(pre[preFirst++]);
        int inIndex=inMap[root->val];

        root->left=construct(pre,in,preFirst,left,inIndex-1);
        root->right=construct(pre,in,preFirst,inIndex+1,right);
        return root;
    }
};
