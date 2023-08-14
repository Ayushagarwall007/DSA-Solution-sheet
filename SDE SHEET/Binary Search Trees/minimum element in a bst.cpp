/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *        Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
 #include<bits/stdc++.h>
// #include <limits.h>

int minVal(Node* root){

// Write your code here.

int ans = INT_MAX;

 

if(root == NULL)

{

return -1;

}

 

while(root != NULL)

{

ans = min(ans, root -> data);

root = root -> left;

}

return ans;

}
