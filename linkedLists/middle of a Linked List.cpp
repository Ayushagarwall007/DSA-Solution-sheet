// given a Linked list , you have to find the middle of that single linked list
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* s = head, *f = head;
        while(f != NULL && f->next != NULL)
        {
            s = s->next;
            f = (f->next)->next;
        }
        return s;
        
        
    }
};


