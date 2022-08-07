// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you 
// will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding 
// original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in 
// the original list and copied list represent the same list state. None of the pointers in the
// new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list,
// x.random --> y.

// Return the head of the copied linked list.

// ArbitLinked List1

// Example 1:

// Input:
// N = 4, M = 2
// value = {1,2,3,4}
// pairs = {{1,2},{2,4}}
// Output: 1
// Explanation: In this test case, there
// are 4 nodes in linked list.  Among these
// 4 nodes,  2 nodes have arbitrary pointer
// set, rest two nodes have arbitrary pointer
// as NULL. Second line tells us the value
// of four nodes. The third line gives the
// information about arbitrary pointers.
// The first node arbitrary pointer is set to
// node 2.  The second node arbitrary pointer
// is set to node 4.
// Example 2:

// Input:
// N = 4, M = 2
// value[] = {1,3,5,9}
// pairs[] = {{1,1},{3,4}}
// Output: 1
// Explanation: In the given testcase ,
// applying the method as stated in the
// above example, the output will be 1.

// Your Task:
// The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

// NOTE : 
// 1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
// 2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N <= 100
// 1 <= M <= N
// 1 <= a, b <= 100
// 

// APPROACH 01
// USING THE HASH MAP TO HASH THE VALUES OF THE SAME NODES OF THE ORIGINAL LIST AND THE CLONE LIST

class Solution
{
  private:
  void insertAtTail(Node* &head,Node* &tail,int d)
  {
    Node*newNode=new Node(d);
    if(head==NULL){
      head=newNode;
      tail=newNode;
      return ;
      
    }
    else
    {
      tail->next=newNode;
      tail=newNode;     }
    }
  
  public:
  Node*copyList(Node* head)
  {
//     step 1 create a clone list
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL)
    {
      insertAtTAil(cloneHead,cloneTail,temp->data);
      temp=temp->next;
    }
    // step 2 create a map for the random pointeres
    unordered_map<Node*,Node*>oldToNew;
    Node*originalNode=head;
    Node*cloneNode=cloneHead;
    while(originalNode!=NULL)
    {
      oldToNew(originalNode)=cloneNode;
      originalNode=originalNode->next;
      cloneNode=cloneNode->next;
      
    }
    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL)
    {
      cloneNode->=random=oldToNew(originalNode->random);
      cloneNode=cloneNode->next;
       originalNode=originalNode->next;
    }
    return cloneNode;
  }
}



// APPROACH 02
class Solution
{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};



