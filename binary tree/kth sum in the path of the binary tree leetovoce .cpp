// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


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
   void solve (TreeNode* root,int k,int &count,vector<int> path)
   {
       if(root==NULL)return;
       path.push_back(root->val);
        // left
       solve(root->left, k,  count, path);
      // right
      solve (root-> right,k, count, path);
       int size=path.size();
       long long sum=0;
       for(int i=size-1;i>=0;i--)
       {
            sum += path[i];
           if(sum==k)
               count++;
           
       }
       path.pop_back();
       }
    
    
    int pathSum(TreeNode* root, int k) {
        vector<int> path;
        int count=0;
        solve(root,k,count,path);
        return count;
    }
};
