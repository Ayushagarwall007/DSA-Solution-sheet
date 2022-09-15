https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node {
	int data;
	Node *left, *right;
};

vector<int> diagonal(Node* root)
{
	vector<int> diagonalVals;
	if (!root)
		return diagonalVals;

	// The leftQueue will be a queue which will store all
	// left pointers while traversing the tree, and will be
	// utilized when at any point right pointer becomes NULL

	queue<Node*> leftQueue;
	Node* node = root;

	while (node) {

		// Add current node to output
		diagonalVals.push_back(node->data);
		// If left child available, add it to queue
		if (node->left)
			leftQueue.push(node->left);

		// if right child, transfer the node to right
		if (node->right)
			node = node->right;

		else {
			// If left child Queue is not empty, utilize it
			// to traverse further
			if (!leftQueue.empty()) {
				node = leftQueue.front();
				leftQueue.pop();
			}
			else {
				// All the right childs traversed and no
				// left child left
				node = NULL;
			}
		}
	}
	return diagonalVals;
}

// Utility method to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Driver program
int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	/* Node* root = newNode(1);
			root->left = newNode(2);
			root->right = newNode(3);
			root->left->left = newNode(9);
			root->left->right = newNode(6);
			root->right->left = newNode(4);
			root->right->right = newNode(5);
			root->right->left->right = newNode(7);
			root->right->left->left = newNode(12);
			root->left->right->left = newNode(11);
			root->left->left->right = newNode(10);*/

	vector<int> diagonalValues = diagonal(root);
	for (int i = 0; i < diagonalValues.size(); i++) {
		cout << diagonalValues[i] << " ";
	}
	cout << endl;

	return 0;
}





Approach 2: Using Queue:
Every node will contribute to the formation of the following diagonal. Only when the element’s left is available will we push it into the queue. We’ll process the node and then go to the right.

Below is the implementation of the above approach:



#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

vector <vector <int>> result;
void diagonalPrint(Node* root)
{
	if(root == NULL)
		return;

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int size = q.size();
		vector <int> answer;

		while(size--)
		{
			Node* temp = q.front();
			q.pop();

			// traversing each component;
			while(temp)
			{
				answer.push_back(temp->data);

				if(temp->left)
					q.push(temp->left);

				temp = temp->right;
			}
		}
		result.push_back(answer);
	}
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	diagonalPrint(root);

	for(int i=0 ; i<result.size() ; i++)
	{
		for(int j=0 ; j<result[i].size() ; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}
