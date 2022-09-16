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

// for balaneced  bst abs(ht(left)-ht(right))<=1

class Solution {
public:
void Inorder(TreeNode* root ,vector <int>&v)
{
if(root== NULL)
return;

    Inorder(root->left , v);
    v.push_back(root->val);
    Inorder(root->right ,v);
    
}

TreeNode* InoderBST(int s ,int e, vector<int> &v)
{
    if(s > e)
        return NULL;
    int mid =(s+e)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = InoderBST(s, mid-1 ,v);
    root->right = InoderBST(mid+1 ,e, v);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> v;
    Inorder(root, v);
    
    return InoderBST(0 ,v.size() -1, v);
}
};
