// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

// // using floyd  loop detection approaach using hash map
class Solution
{
    public:
    bool hasCycle(ListNode *head)
    {
        if(head==NULL||head->next==NULL)return false;
        ListNode *temp=head;
        unordered_map<ListNode*,bool>map;
        while(temp!=NULL)
        {
            if(map[temp->next])return true;// this means that the node has already visited
            else
            map[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};


// using the two pointer;s approach
class Solution
{
    public:
    bool hasCycle(ListNode* head)
    {
        // if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
    
};
