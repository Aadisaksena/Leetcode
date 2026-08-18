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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        // Check the immediately previous inorder node
        if (prev != nullptr && prev->val > root->val) {

            // First violation
            if (first == nullptr)
                first = prev;

            // Current node of the latest violation
            second = root;
        }

        // Move prev to the current node
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap the two wrong values
        swap(first->val, second->val);
    }
};