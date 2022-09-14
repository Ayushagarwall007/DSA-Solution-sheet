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
    
    void viewgenerator(TreeNode* root,vector<int>&res,set<int> &s,int currLevel)
    {
        if(root==NULL)return;
        if(s.find(currLevel)==s.end())
        {
            s.insert(currLevel);
            res.push_back(root->val);
        }
      // this is for right sidde ... for left side first traverse for left and then for right
      
        viewgenerator( root->right,res,s,currLevel+1);
        viewgenerator( root->left,res,s,currLevel+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        set<int> s;
        viewgenerator(root,res,s,0);
        return res;
      
    }
};
