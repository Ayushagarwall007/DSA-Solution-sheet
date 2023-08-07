/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
void solve(BinaryTreeNode<int>*root,vector<string>&ans,string v)
{
    if(!root->left and !root->right)
    {
        
        v+=to_string(root->data);
        ans.push_back(v);
        v.pop_back();
        return;
    }
    v+=to_string(root->data)+" ";
    if(root->left)
    {
        solve(root->left,ans,v);
        
    }
    if(root->right)
    {
        solve(root->right,ans,v);
    }
    
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string>ans;
    string v="";
    solve(root,ans,v);
    return ans;
}
