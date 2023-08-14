/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void solve(TreeNode* root,int key,int &pre, int &succ)
{
    if(root==NULL)return;
    solve(root->left,key,pre,succ);
    if(root->data<key)
    {
        pre=root->data;
    }
    else if(root->data>key and succ==-1)
    {
        succ=root->data;
    }
    solve(root->right,key,pre,succ);
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pre=-1;
    int succ=-1;
    if(root==NULL)return {-1,-1};
    solve(root,key,pre,succ);
    return {pre,succ};
}
