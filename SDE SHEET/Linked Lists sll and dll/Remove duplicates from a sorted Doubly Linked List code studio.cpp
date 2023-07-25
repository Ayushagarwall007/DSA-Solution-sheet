/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    if(head==NULL)return NULL;
    
    Node* curr=head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) and (curr->data)==(curr->next->data))
        {
            Node* next_next=curr->next->next;
            Node* nodeToDelete=curr->next;
            delete nodeToDelete;
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}











// Node * removeDuplicates(Node *head)
// {
//     Node* curr=head,*mainPtr=head,*prevs;
//     curr=curr->next;
//     while(curr)
//     {
//         if(curr and curr->prev->data==curr->data)
//         {
//             prevs=curr->prev;
//             Node* next=curr->next;
//             curr->next=NULL;
//             curr->prev=NULL;
//             delete curr;
//             prevs->next=next;
//             if(next)
//                 next->prev=prevs;
//             curr=next;
            
//         }
//         else
//             curr=curr->next;
//     }
//     return mainPtr;
// }

