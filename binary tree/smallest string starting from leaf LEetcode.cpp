// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// As a reminder, any shorter prefix of a string is lexicographically smaller.

// For example, "ab" is lexicographically smaller than "aba".
// A leaf of a node is a node that has no children.


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
    
    string s="";
    bool lexi(string s1, string s2)
    {
        // cout<<s1<<" "<<s2<< " "<<endl;
        if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end()))      // inbuilt func. to compare two strings lexicographically
         return true;      // if s1>s2
        else
            return false ;  // else if s2>s1
    }
    
    void f(TreeNode* root,string str)
    {
        if(root->right== NULL and root->left==NULL)
        {
            str=char(root->val+97)+str;
            if(s=="")s=str;
            else
            {
                // cout<<str<<" ";
                if(lexi(str,s))s=str;
            }
            return ;
        }
        
        str=char(root->val+97)+str;
       
        if(root->left)f(root->left,str);
        if(root->right)f(root->right,str);
    }
    
    
    string smallestFromLeaf(TreeNode* root) {    
    string temp="";
        f(root,"");
        return s;
        
    
    
    }   
};
