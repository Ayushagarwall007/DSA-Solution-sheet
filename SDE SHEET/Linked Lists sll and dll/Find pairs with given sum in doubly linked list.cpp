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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    if(head==NULL or head->next==NULL)return {};
    vector<pair<int,int>>ans;
    Node* l=head;
    Node* r=head;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    while(l!=r and r->next!=l)
    {
        if(l->data + r->data ==k)
        {
            ans.push_back({l->data,r->data});
            l=l->next;
            r=r->prev;
        }
        else if(r->data+l->data>k)
        {
            r=r->prev;
        }
        else{
            l=l->next;
        }
    }
    return ans;
}
