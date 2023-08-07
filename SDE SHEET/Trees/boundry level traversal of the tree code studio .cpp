#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftTraversal(TreeNode<int>*root, vector<int>&ans)
{
    if(root==NULL)return ;
    if(root->left==NULL and root->right==NULL)return;
    
    ans.push_back(root->data);
    if(root->left)
    {
        leftTraversal(root->left,ans);
    }
    else
    {
        leftTraversal(root->right, ans);
    }
}


void leafTraversal(TreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL) return;
    if(root->left ==NULL and root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}

void rightTraversal(TreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL and root->right==NULL)
    {
        return;
    }
    if(root->right)
    {
        rightTraversal(root->right,ans);
    }
    else
    {
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->data);
}




vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(root==NULL)return ans;
    ans.push_back(root->data);
    //left traversal except root and leaf node
    leftTraversal(root->left,ans);

    // all leaf nodes traversal
    leafTraversal(root->left ,ans);
    leafTraversal(root->right,ans);

    // right traversals except root and leaf node
    rightTraversal(root->right,ans);
    


    return ans;
}
