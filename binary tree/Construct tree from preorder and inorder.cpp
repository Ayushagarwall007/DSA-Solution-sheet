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

// inorder is L N R
// preorder is N L R

// so isme huum phle node dekhenge preorder se or phir uss node ko inorder se compare kaarke hum left or right part nikalenge or haar left or right part uskaa inorder or preorder se compare hogaa 
//  jaab hum find element find kaarenge inorder mai to start se pos tkk left paar hogaa root kaa or pos+1 se inorder ke last tkk  right part hogaa root kaaa

// abb humm ek case solve kaarenge or baaki kaa recursion sambhal legaa
 


class Solution {
public:
    void createMapping(vector<int>in, map<int,int> &nodeToIndex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodeToIndex[in[i]]=i;
        }
    }
    
    
    TreeNode* solve(vector<int> &in,vector<int>&pre,int & index,int inOrderStart,int inOrderEnd,int n, map<int,int> &nodeToIndex)
    {
         if(index>=n or inOrderStart> inOrderEnd)
             return NULL;
        
        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        
        int position=nodeToIndex[element];
        
        root->left=solve(in,pre,index,inOrderStart,position-1,n,nodeToIndex);
        root->right=solve(in,pre,index,position+1,inOrderEnd,n,nodeToIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size();
        int preOrderIndex=0;
        map<int,int> nodeToIndex; // map to store the index of the elements of the inorder array
        createMapping(inorder,nodeToIndex,n);
        
      TreeNode* ans=  solve(inorder,preorder,preOrderIndex,0,n,n,nodeToIndex);
        
        return ans;
    }
};
