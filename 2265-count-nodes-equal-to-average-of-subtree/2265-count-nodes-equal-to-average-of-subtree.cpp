/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int findSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return root->val + findSum(root->left) + findSum(root->right);
    }

    int findSize(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + findSize(root->left) + findSize(root->right);
    }

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        int sum = findSum(root);
        int size = findSize(root);

        if (sum / size == root->val)
            ans++;

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans-1;
    }
};