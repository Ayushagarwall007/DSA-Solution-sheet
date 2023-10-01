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
    bool hasCycle(ListNode *head) {
        // if(head==NULL)return false;
        // ListNode *slow=head;
        // ListNode *fast=head;
        // while(fast!=NULL and fast->next!=NULL)
        // {
        //     slow = slow->next ;
        //     fast = fast->next->next ;
        //     if(slow==fast)return true;
        // }
        // return false;

        if(head==NULL)return false;
        unordered_map<ListNode* , bool>mp;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(mp[temp->next]){return true;break;}
            mp[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};


