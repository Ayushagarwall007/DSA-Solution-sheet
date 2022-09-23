// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// // 1 <= Node.val <= 1000




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
    void reorderList(ListNode* head) {
        ListNode* head1;
        ListNode* head2;
        
        int count = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            count++;
            cur = cur->next;
        }
        
        if(count <=2) return;
        
        int mid = count/2;
        if(count%2 != 0) mid = mid+1;
        
        cur = head;
        head1 = head;
        for(int i = 0; i<count; i++){
            if(i == mid-1){
                head2 = cur->next;
                cur->next = NULL;
                break;
            }
            cur = cur->next;
        }
        
        //Reverse second list
        cur = head2->next;
        head2->next = NULL;
        while(cur!=NULL){
            ListNode* next = cur->next;
            cur->next = head2;
            head2 = cur;
            cur = next;
        }
        
        //Reassemble
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        
        while(cur2!=NULL){
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;
            
            cur2->next = cur1->next;
            cur1->next = cur2;
            
            cur1 = next1;
            cur2 = next2;
        }
    }
    
};
