// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:


// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// Example 2:

// Input: root = [1,null,3]
// Output: [1,3]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100



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


// class Solution {
// public:
    
//     void viewgenerator(TreeNode* root,vector<int>&res,set<int> &s,int currLevel)
//     {
//         if(root==NULL)return;
//         if(s.find(currLevel)==s.end())
//         {
//             s.insert(currLevel);
//             res.push_back(root->val);
//         }
//         viewgenerator( root->right,res,s,currLevel+1);
//         viewgenerator( root->left,res,s,currLevel+1);
        
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
        
//         set<int> s;
//         viewgenerator(root,res,s,0);
//         return res;
      
//     }
// };



class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* curr;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i = 0;i<size;i++)
            {
                curr = q.front();
                 if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
               
                temp.push_back(curr->val);
                q.pop();
            }
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};
