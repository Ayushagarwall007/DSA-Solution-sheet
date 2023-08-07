/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){

    // Write your code here.

    if(root==NULL or (!root->left and !root->right))

        return true;

    return root->data==((root->left?root->left->data:0)+(root->right?root->right->data:0)) and isParentSum(root->left) and isParentSum(root->right);

}
