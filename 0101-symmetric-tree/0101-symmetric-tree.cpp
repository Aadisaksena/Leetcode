class Solution {
public:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr)
            return true;

        if (a == nullptr || b == nullptr)
            return false;

        return (a->val == b->val) &&
               isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return isMirror(root->left, root->right);
    }
};