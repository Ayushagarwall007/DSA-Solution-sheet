// question 01 reverse  k group in a linked list.... agar last kaa k group total length kaa multiple nahi hai to jo baaki ke elements hai unko bhi reverse kaar do ]
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





// Question 02 // question 01 reverse  k group in a linked list.... agar last kaa k group total length kaa multiple nahi hai to jo baaki ke elements hai unko  same chodd doo
// unko reversee naa kaaro
// LEETCODE Question 25 reverse nodes in k  Group


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public:   ListNode* reverseList(ListNode* n)
    {   
        ListNode* prev=nullptr;
        while(n)
        {
            ListNode* Next=n->next;
            n->next=prev;
            prev=n;
            n=Next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left=head;
        ListNode* right=head;
        ListNode* prev=nullptr;
        while(right)
        {   int count=1;
            while((right)&&(count<k))
            {right=right->next;count++;}
            if(right)
            {ListNode* current=right->next;
             right->next=nullptr;
           ListNode* n=reverseList(left);
           
            if(left==head)
            head=n;
            else
            prev->next=n;
            
            left->next=current;
            right=current;
            prev=left;
            left=right;
        
            }
        }
        return head;
    }

// Time Complexity: O(2*n)
// Space Complexity: O(1)
    
};
