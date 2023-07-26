// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109





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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
       
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        int count=1;
        ListNode* cnt=head;
        while(cnt->next!=NULL)
        {
            cnt=cnt->next;
            count++;
        }
        k=k%count;
        while(k--)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = head ;
            head=temp;
           
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            temp=head;
            
        }
        return head;
     }
};
