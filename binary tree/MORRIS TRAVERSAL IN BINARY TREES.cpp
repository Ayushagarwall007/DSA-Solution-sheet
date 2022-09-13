// // this treversal is used to do the inorder traversal in O(N) time and in O(1) space 
// this is an iterative approach to find the inorder traversal
// isme hum haar root node kaa link banaa kaar rakh dete hai phle hum left mai jayegne or jaabtaak uskaa right NULL nahi hogaa tbb tkk hum traverser kaarenge 
// orr jaise hii uskaa next null hojegaa to humm uskaa next root ko kaar denge or current = root->left kaar denge
// jaise hii root-> left==NULL ho jaegaa hum usse print kaar denge


// 1. Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Find rightmost node in current left subtree OR
//               node whose right child == current.
//          If we found right child == current
//              a) Update the right child as NULL of that node whose right child is current
//              b) Print current’s data
//              c) Go to the right, i.e. current = current->right
//          Else
//              a) Make current as the right child of that rightmost 
//                 node we found; and 
//              b) Go to this left child, i.e., current = current->left


#include <bits/stdc++.h>
using namespace std;

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
 int data;
 struct tNode* left;
 struct tNode* right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
 struct tNode *current, *pre;

 if (root == NULL)
  return;

 current = root;
 while (current != NULL) {

  if (current->left == NULL) {
   cout << current->data << " ";
   current = current->right;
  }
  else {

   /* Find the inorder predecessor of current */
   pre = current->left;
   while (pre->right != NULL
    && pre->right != current)
    pre = pre->right;

   /* Make current as the right child of its
   inorder predecessor */
   if (pre->right == NULL) {
    pre->right = current;
    current = current->left;
   }

   /* Revert the changes made in the 'if' part to
   restore the original tree i.e., fix the right
   child of predecessor */
   else {
    pre->right = NULL;
    cout << current->data << " ";
    current = current->right;
   } /* End of if condition pre->right == NULL */
  } /* End of if condition current->left == NULL*/
 } /* End of while */
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
 struct tNode* node = new tNode;
 node->data = data;
 node->left = NULL;
 node->right = NULL;

 return (node);
}

/* Driver program to test above functions*/
int main()
{

 /* Constructed binary tree is
   1
  / \
  2  3
 / \
 4  5
*/
 struct tNode* root = newtNode(1);
 root->left = newtNode(2);
 root->right = newtNode(3);
 root->left->left = newtNode(4);
 root->left->right = newtNode(5);

 MorrisTraversal(root);

 return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
