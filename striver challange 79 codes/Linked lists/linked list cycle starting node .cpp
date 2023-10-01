/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head , *fast=head , *check=head;
        bool flag=false;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            while(check!=slow)
                {
                    check=check->next;
                    slow=slow->next;
                }
                return slow;
        }
        return NULL;
        
    }
};
