int Floor(BinaryTreeNode<int> *root, int input)
{
	int floor=-1;
	while(root)
	{
		if(input==root->data)
		{
			floor=root->data;
			return floor;
		}
		else if(input>root->data)
		{
			floor=root->data;
			root=root->right;
		}
		else{
			root=root->left;
		}
	}
	return floor;
}
