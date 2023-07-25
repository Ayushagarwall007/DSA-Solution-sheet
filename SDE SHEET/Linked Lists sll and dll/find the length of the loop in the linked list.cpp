/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int getcout(Node * slow){

    Node * curr=slow;

    Node* temp=slow->next;

    int cnt=1;

    while(curr!=temp){

        cnt++;

        temp=temp->next;

    }

    return cnt;

}

int lengthOfLoop(Node *head) {
    // Write your code here

    Node * slow=head;

    Node * fast=head;

    int cout=0;

    while(fast!=NULL && fast->next !=NULL)
    {
         slow=slow->next;

         fast=fast->next->next;
         if(slow==fast)
         {
            cout= getcout(slow);
            return cout;
         }

    }

    return 0;

 

}

 
