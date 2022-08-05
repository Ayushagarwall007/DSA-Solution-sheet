#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    
    // when we create a new node this constructer willl run
    Node(int data)
    {
        this->data=data;
        this->next=NULL;

    }
    // destructor that is being called while deleting the node
    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL ){
        delete next;
        this->next=NULL;
        }
        cout<<"memory is free for the node with data "<<value<<endl;
    }
};

 void insertAtHead(Node*&head,int d)
{
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void print(Node* &head)
{
    if(head==NULL)
    {
        cout<<"the list is empty"<<endl;
       return ; 
    }
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &tail,Node* &head, int position,int d)
{
    // insert at the start
    if(position ==1)
    {
        insertAtHead(head,d);
        return ;
    }
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)// inserting at the last position
    {
        insertAtTail(tail,d);
    }
    // creating a node for the position d
    Node * nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}


void deleteNode(int position , Node*&head)
{
    // deleting for the first and the last node
    if(position==1)
    {
        Node*temp=head;
        head=head->next;
        //memory free for the start node
        temp->next=NULL;
        delete temp;

    }
    else
    {
        // deleting any moiddle node or the last node
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count <position)
        {
            prev=curr;
            curr=curr->next;
            count++;

        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

int main()
{
    // creating a new node
    Node*node1=new Node(10);
     
     Node*head=node1;// head pointing to node 1
     Node*tail=node1;

     insertAtTail(tail,30);
     insertAtTail(tail,34);
     insertAtTail(tail,21);


     insertAtPosition(tail,head,4,22);
     //print head;

}
