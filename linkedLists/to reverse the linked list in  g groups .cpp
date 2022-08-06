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
    ListNode* reverseKGroup(ListNode* head, int k) {
//         using recursion phle first k nodes ko revese kaar do baaki kaa recursion dekh legaa
//         base case
        if(head==NULL)
            return NULL;
        
        //   step 1:- reverse first K nodes
        ListNode* forward=NULL;
        ListNode*curr=head;
        ListNode *prev=NULL;
        int count =0;
        while(curr!=NULL and count <k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        
        // aage kaa saara part recursion dekh legaa
        if(forward!=NULL)
        {
            head->next=reverseKGroup(forward,k);
        } 
         
//         step 3 :- return tthe head of the reversed linked list
        return prev;
        
    }
};
