/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& visited, int depth) {
        if (root == NULL)
            return;

        // Store the first node seen at this depth
        if (visited[depth] == -101)
            visited[depth] = root->val;

        // Visit right first so the first node is the rightmost one
        solve(root->right, visited, depth + 1);
        solve(root->left, visited, depth + 1);
    }

    int maxdepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};

        int d = maxdepth(root);

        // One entry for each level
        vector<int> visited(d, -101);

        solve(root, visited, 0);

        return visited;
    }
};