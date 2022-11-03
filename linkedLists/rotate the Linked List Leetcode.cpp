// 61. Rotate List
// Medium
// 6.7K
// 1.3K
// Companies
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
       
        ListNode *temp = head, *ptr = head;
        
		// if  list is empty return NULL
        if(head == NULL)
            return NULL;
			
        // if  list contain 1 node return NULL
        if(head -> next == NULL)
            return head;
        
        int cnt = 1;
        
		// counting nodes in list
        while(temp->next != NULL)
        {
            temp = temp -> next;
            cnt++;
        }
		
		// mod of k with cnt to find the minimum no of rotations.
        k = k % cnt;
        
        while(k--)
        {
            while(temp->next != NULL)
                temp = temp -> next;
        
            temp -> next = head;           //making it a circular linked list
			
			// making last node the new head
            head = temp;
            ptr = temp;
			
			// moving list values one by one
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            
			// adding NULL at end of list
            temp -> next = NULL;
			
            temp = ptr;
            
        }
        return head;
    }
};
