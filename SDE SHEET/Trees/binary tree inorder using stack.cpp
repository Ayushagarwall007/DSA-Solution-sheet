
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // l n r
        
        vector<int> traversal;
        if (root==NULL)return traversal;
        stack<TreeNode*> stk;
        TreeNode* node= root;
        while (true){
            if (node!= NULL){
                stk.push(node);
                node=node->left;
            }
            else{
                if (stk.empty())break;
                node= stk.top();
                stk.pop();
                traversal.push_back(node->val);
                node=node->right;
            }
        }
        return traversal;
    }
};
