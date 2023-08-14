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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return 0;
        priority_queue<int,vector<int>,greater<int>>gp;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0)
        {
            int s=q.size();
            while(s--)
            {
                TreeNode* tmp=q.front();
                q.pop();
                gp.push(tmp->val);
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
        }
        k--;
        while(k--)
        {
            gp.pop();
        }
        int ans=gp.top();
        return ans;
        }
};
