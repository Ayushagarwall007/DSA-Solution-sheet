// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.



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
map<int,int>mp;
void mapping(vector<int>&inorder,int size)
{
    for(int i=0;i<size;i++)
    {
        mp[inorder[i]]=i;
    }

}
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &size,int &preindex,int inorderStart,int  inorderEnd)
{
    if((preindex>=size) or (inorderStart>inorderEnd))return NULL;
    int ele=preorder[preindex++];
    TreeNode * root=new TreeNode(ele);
    int pos=mp[ele];
    root->left=solve(preorder,inorder,size,preindex,inorderStart,pos-1);
    root->right=solve(preorder,inorder,size,preindex,pos+1,inorderEnd);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int preIndex=0,inorderstart=0,inorderend=size-1;
        mapping(inorder,size);
        return solve(preorder,inorder,size,preIndex,inorderstart,inorderend);
    }
};
