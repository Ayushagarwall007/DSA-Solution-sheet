// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.


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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummyNode=new ListNode(-1);
//         this dummy node  is created to handle all the corner cases of the linked list
//         now adding the dummy node before the head node
        dummyNode->next=head;
        
        
        ListNode*prev=dummyNode;
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            bool flag = false;
            while(curr->next!=NULL && curr->val==curr->next->val)
            {
                flag=true;
                curr=curr->next;
            }
            if(flag)// this means that the nodes with the duplicate values occurs;
            {
                prev->next=curr->next;
                curr=curr->next;
                
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return dummyNode->next;// at last after deleting the duplicates we are removing the head of the linked list
    }
};
