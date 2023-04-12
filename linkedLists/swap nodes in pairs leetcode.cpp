// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100




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
    ListNode* swapPairs(ListNode* head) {
        // using the iterative method
        if(!head or !head->next)return head;
        ListNode* dummyNode=new ListNode();

        ListNode * prevNode=dummyNode;
        ListNode * currNode=head;

        while(currNode  and currNode->next)
        {
             prevNode->next=currNode->next;
             currNode->next=prevNode->next->next;
             prevNode->next->next=currNode;
             prevNode=currNode;
             currNode=currNode->next;
        }
        return dummyNode->next;
    }
};





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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* node) {
//         if(node==NULL or node->next==NULL)return node;
//         ListNode* nextPair=swapPairs(node->next->next);
//         ListNode* temp=node->next;
//         temp->next=node;
//         node->next=nextPair;

//         return temp;
//     }
// };
