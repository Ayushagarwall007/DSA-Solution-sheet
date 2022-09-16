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

// jjab bhi agar kissi node ko delete kaarna hai or uske dono child non null hai to humm yaa to left se max value nikaal ke usko node ke data se replace kaarenge or uss maximum node ko delete kaarenge yaa hum node ke right se min value nikaalenge oer same procedure filloe up karenge..
class Solution {
public:
    
    TreeNode* find_inorder_succ(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        
        if(root -> left == NULL)
            return root;
        
        return find_inorder_succ(root -> left);
    }

    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // base case
        
        if(root == NULL)
            return NULL;
        
        // if key is present on left side
        
        if(root -> val > key)
        {
            root -> left = deleteNode(root -> left, key);
        }
        
        // if key is present on right side
        
        else if(root -> val < key)
        {
            root -> right = deleteNode(root -> right, key);
        }
        
        // if key found
        
        else
        {
            // if node is leaf node, then simply delete the node
            
            if(root -> left == NULL && root -> right == NULL)
            {
                delete root;
                
                return NULL;
            }
            
            // if node has only right subtree, delete the node and replace it with right subtree
            
            else if(root -> left == NULL)
            {
                TreeNode* temp = root -> right;
                
                delete root;
                
                return temp;
            }
            
            // if node has only left subtree, delete the node and replace the node with left subtree
            
            else if(root -> right == NULL)
            {
                TreeNode* temp = root -> left;
                
                delete root;
                
                return temp;
            }
            
            // if node has both the subtree, then find the inorder successor of node and replace the node with inorder successor
            
            else
            {
                // find the inorder successor
                
                TreeNode* successor = find_inorder_succ(root -> right);
                
                // replace the node with inorder successor
                
                root -> val = successor -> val;
                
                // call deleteNode for deleting inorder successor
                
                root -> right = deleteNode(root -> right, successor -> val);
            }
        }
        
        return root;
    }
};
