// Problem Statement

// Sample Input 1 :
// 2
// 5
// 3 4 6  -1
// 5 11 14 -1
// 22 25 -1
// 26 28 -1
// 39  -1
// 4
// 1 2 3 -1
// 8 10 15 -1
// 18 22 -1
// 29 -1
// Sample Output 1 :
// 3 4 5 6 11 14 22 25 26 28 39
// 1 2 3 4 6 8 10 15 18 22 29
// Explanation For Sample Input 1:
// For the first test case:
// The given linked list is :

// Therefore after flattening the list will become-
// 3 -> 4 ->  5 ->  6 -> 11 -> 14 -> 22 -> 25 -> 26 -> 28 -> 39->null
// Note that: the list after flattening should be sorted!

// For the second test case:

// The given linked list is 

// Therefore after flattening the list will become-
// 1 -> 2 ->  3 ->  4 -> 6 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null
// Sample Input 2 :
// 3
// 5
// 4 6 -1
// 5 71 -1
// 7 8 9 -1
// 11 12 19 -1
// 14 15 17 -1
// 2
// 3 4 -1
// 5 6 7 8 -1
// 1
// 3 -1 
// Sample Output 2 :
// 4 5 6 7 8 9 11 12 14 15 17 19 71
// 3 4 5 6 7 8
// 3



#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* a,Node* b)
{
    Node* temp=new Node(1);
    Node* res=temp;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<=b->data)
        {
            temp->child=a;
            a=a->child;
            temp=temp->child;
            temp->next=NULL;
        }
        else
        {
            temp->child=b;
            b=b->child;
            temp=temp->child;
            temp->next=NULL;
        }
    }
    if(a!=NULL)
        temp->child=a;
    if(b!=NULL)
        temp->child=b;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
    // Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    head->next=flattenLinkedList(head->next);
    return merge(head,head->next);
}



// issme humm phle last 2 vertical ll ko merge kaarege using the concept of merging two sorted linked list phir last 3rd ko merged ll se merge kaarege 
// in this similar mannner using recursion we merge multilevel sorted single linked list using recursion.
