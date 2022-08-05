// wap to reverse a single linked list 

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

// using iterative method

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* first=NULL,*second=NULL,*curr=head;
        while(curr)
        {
            first=curr->next;
            curr->next=second;
            second=curr;
            curr=first;
        }
        return second;
    }
};


// RECURSIVE APPROACH 01
class Solution {
public:
    void reverse(ListNode*&head,ListNode * curr,ListNode* prev)
    {
//         base case
        if(curr==NULL)
        {
            head=prev;
            return ;
        }
        ListNode* forward=curr->next;
        reverse(head,forward,curr);
            curr->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
       ListNode* curr=head;
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        return head;
    }
};



 
