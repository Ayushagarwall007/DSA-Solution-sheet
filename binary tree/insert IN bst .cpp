#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    
    Node( int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBst(Node* root,int data)
{
    // base case
    if(root==NULL) {
    root=new Node(data);
    return  root;
    }
    
    if(data>root->data)
    {
        // move into the right part of the tree
        root->right=insertIntoBst(root->right,data);
    }
    else {
        root->left = insertIntoBst(root->left,data);
    }
    return root;
}

void takeInput(Node * &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
      root=  insertIntoBst(root,data);
        cin>>data;
    }
}
int main()
{
    Node* root= NULL;
    cout<<"Enter the sata to create the BST";
    takeInput(root);
}
