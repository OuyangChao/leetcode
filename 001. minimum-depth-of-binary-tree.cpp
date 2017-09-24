/*
Given a binary tree, find its minimum depth.The minimum depth is the number of nodes 
along the shortest path from the root node down to the nearest leaf node.

给定一颗二叉树，求它的最小深度。最小深度是从根结点到它最近的叶节点的最短距离。
*/

/*
思路：递归找最小深度
*/

class Solution {
public:
    int run(TreeNode *root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		int m = run(root->left) + 1;
		int n = run(root->right) + 1;
		m = (m == 1 ? INT_MAX : m);
		n = (n == 1 ? INT_MAX : n);
		return min(m, n);
    }
};