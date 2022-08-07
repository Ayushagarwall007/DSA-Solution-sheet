/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
void insertAtTail(Node*&tail,Node* curr)
{
    tail->next=curr;
    tail=curr;
}
// creating the seprate list of 0 1 and 2's
Node* sortList(Node *head)
{
   Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
     Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
     Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;
    
    Node* curr= head;
    while(curr!=NULL)
    {
        int value= curr->data;
        if(value==0)
        {
            insertAtTail(zeroTail,curr);
        }
        else if(value==1)
            insertAtTail(oneTail,curr);
        else if(value==2)
            insertAtTail(twoTail,curr);
        curr=curr->next;
    }
    
//     merge 3 of the sublist
//     if list 1 is not empty
    if(oneHead->next!=NULL)
        zeroTail->next=oneHead->next;
    else// this means that the list 1 is empty
        zeroTail->next=twoTail->next;
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    
    
//     setup of the head
    head=zeroHead->next;
    
//     delete dummy head
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
        
    
    
}
