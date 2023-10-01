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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode*p=head;
        while(p)
        {
            length++;
            p=p->next;
        }
        if(n==length)
        {
            return head->next;
        }
        length-=n;
        length--;
        p=head;
        while(length--)
            p=p->next;
        p->next=p->next->next;

        return head;
    }
};
