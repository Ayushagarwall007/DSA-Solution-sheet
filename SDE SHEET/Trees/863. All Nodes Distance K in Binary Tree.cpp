// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getparentbyBFS(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left){
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                      parent[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
   void getparentbyDFS(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*root){
       if(root==NULL)
       return;
       if(root->left!=NULL){
         parent[root->left]=root;
       }
       if(root->right!=NULL){
           parent[root->right]=root;
       }
       getparentbyDFS(parent,root->left);
        getparentbyDFS(parent,root->right);
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        getparentbyDFS(parent,root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        int lev=0;
        while(!q.empty()){
            int n=q.size();
            if(lev==k)
                break;
            lev++;
            while(n--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left&&!vis[curr->left]){
                    vis[curr->left]=true;
                    q.push(curr->left);
                }
                 if(curr->right&&!vis[curr->right]){
                    vis[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr]&&!vis[parent[curr]]){
                    vis[parent[curr]]=true; 
                    q.push(parent[curr]);
                }
            }
        }
        vector<int>ans;
        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
