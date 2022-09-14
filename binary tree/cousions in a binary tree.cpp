// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


class Solution {
public:

	unordered_map<int, pair<int,int>> mp;
	void solve(TreeNode* root, int level, int parent){

		if(root == NULL){
			return;
		}

		mp[root->val] = {level, parent};

		solve(root->left, level + 1, root->val);
		solve(root->right, level + 1, root->val);
	}

	bool isCousins(TreeNode* root, int x, int y) {

		solve(root, 0, -1);

		if(mp[x].first == mp[y].first && mp[x].second != mp[y].second){
			return true;
		}

		return false;
	}
};
