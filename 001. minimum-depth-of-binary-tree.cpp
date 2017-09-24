/*
Given a binary tree, find its minimum depth.The minimum depth is the number of nodes 
along the shortest path from the root node down to the nearest leaf node.

����һ�Ŷ���������������С��ȡ���С����ǴӸ���㵽�������Ҷ�ڵ����̾��롣
*/

/*
˼·���ݹ�����С���
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