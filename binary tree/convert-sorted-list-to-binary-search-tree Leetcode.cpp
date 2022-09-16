// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

// Example 1:


// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private: 
    TreeNode* inorderToBst(vector<int>& ans,int start, int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=inorderToBst(ans,start,mid-1);
        root->right=inorderToBst(ans,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        
        TreeNode* root=inorderToBst(ans,0,ans.size()-1);
        return root;
    }
};
