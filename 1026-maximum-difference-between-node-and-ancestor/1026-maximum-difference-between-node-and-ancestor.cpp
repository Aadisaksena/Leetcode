/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* node, int mn, int mx) {
        if (node == nullptr)
            return mx - mn;

        mn = min(mn, node->val);
        mx = max(mx, node->val);

        int left = dfs(node->left, mn, mx);
        int right = dfs(node->right, mn, mx);

        return max(left, right);
    }
};