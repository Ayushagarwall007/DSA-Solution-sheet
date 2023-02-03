// Problem Statement
// Sample Input 1:
// 2
// 1 4 5 -1
// 2 3 5 -1
// 7 8 -1
// 1 3 4 6 -1
// Sample Output 1:
// 1 2 3 4 5 5 -1
// 1 3 4 6 7 8 -1
// Explanation Of Input 1:
// The first test case is already explained in the problem statement.

// The second test case, the first list is: 7 -> 8 -> NULL
// The second list is: 1 -> 3 -> 4 -> 6 -> NULL
// The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL
// Sample Input 2:
// 2
// 5 -1
// 1 3 6 10 -1
// 1 1 1 -1
// 1 1 1 -1
// Sample Output 2
// 1 3 5 6 10 -1
// 1 1 1 1 1 1 -1



#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
            
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }
    Node<int>* curr1=first;
   Node<int>* next1=curr1->next;
    Node<int>* curr2= second;
    Node<int>* next2=curr2->next;
    while(curr2!=NULL&&next1!=NULL)
    {
        if((curr2->data >= curr1->data)&&(curr2->data<=next1->data)
           {
               curr1->next=curr2;
               next2=curr2->next;
               curr2->next=next1;
               curr1=curr2;
               curr2=next2;
           }
           else
           {
               curr1=next1;
               next1=next1->next;
           }
               
               if(next1==NULL)
               {
                   curr1->next=curr2;
                   return first;
               }
               
           
    }
           return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)return second;
    if(second==NULL)return first;
    if(first->data<=second->data)
    {
      return   solve(first,second);
    }
    else
       return solve(second,first);
}
