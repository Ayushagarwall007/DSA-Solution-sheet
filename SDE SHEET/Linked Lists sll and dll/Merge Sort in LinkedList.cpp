// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105
 

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?




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
ListNode* findMid(ListNode *head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* mergeTwoLists(ListNode* list1 , ListNode* list2)
{
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;
    ListNode* temp1;
    if(list1->val<=list2->val)
    {
        temp1=list1;
        list1=list1->next;
    }
    else
    {
        temp1=list2;
        list2=list2->next;
    }
    ListNode* temp2=temp1;
    while(list1!=NULL and list2!=NULL)
    {
        if(list1->val<=list2->val)
        {
            temp1->next=list1;
            list1=list1->next;
        }
        else
        {
            temp1->next=list2;
            list2=list2->next;
        }
        temp1=temp1->next;
    }
    while(list1!=NULL)
    {
        temp1->next=list1;
        list1=list1->next;
        temp1=temp1->next;
    }
    while(list2!=NULL)
    {
        temp1->next=list2;
        list2=list2->next;
        temp1=temp1->next;
    }
    return temp2;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)return head;
        ListNode* mid=findMid(head);
        ListNode* rightHead=mid->next;
        mid->next=NULL;
        ListNode* leftHead=head;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        ListNode* ans=mergeTwoLists(leftHead,rightHead);
        return ans;
    }
};
