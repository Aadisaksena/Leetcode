class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr)
            return nullptr;

        // Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Found the node
        else {

            // Case 1: No left child
            if (root->left == nullptr)
                return root->right;

            // Case 2: No right child
            if (root->right == nullptr)
                return root->left;

            // Case 3: Two children
            // Find inorder successor
            TreeNode* successor = root->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            // Replace current value with successor's value
            root->val = successor->val;

            // Delete the successor
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};