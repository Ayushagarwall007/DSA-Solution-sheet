/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/

// bool isPalindrome(Node *head)
// {
//     Node* curr=head;
//     vector<int>arr;
//     int j=0;
//     while(curr!=NULL)
//     {
//         j++;
//         arr.push_back(curr->data);
//         curr=curr->next;   
//     }
//     int i=0;
//     j--;
//     while(i<j)
//     {
//         if(arr[i]!=arr[j])return false;
//         i++;
//         j--;
//     }
//     return true;
// }
#include<bits/stdc++.h>


// bool isPalindrome(Node* head)
// {
   
//     if(head == NULL || head->next == NULL) return true;
// 	Node* slow = head;
// 	Node* fast = head->next;
// 	stack<int> s;
// 	s.push(slow->data);
// 	while(fast != NULL && fast->next != NULL){
// 		slow = slow->next;
// 		s.push(slow->data);
// 		fast = fast->next->next;
// 	}
// 	if(fast == NULL) s.pop();
// 	slow = slow->next;
// 	while(slow != NULL){
// 		int num = s.top();
// 		s.pop();
// 		if(num != slow->data) return false;
// 		slow = slow->next;
// 	}
// 	return true;
// }
void reverse(Node* &head)
{
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL)
    {
        Node* adv=curr->next;
        curr->next=prev;
        prev=curr;
        curr=adv;
    }
    head=prev;
}

bool isPalindrome(Node* head)
{
    Node *slow=head;
    Node* fast=head;
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=slow->next;
    reverse(slow);
    fast=head;
    while(slow!=NULL)
    {
        if(fast->data!=slow->data)return false;
        slow=slow->next;
        fast=fast->next;
        
    }
    return true;
}
