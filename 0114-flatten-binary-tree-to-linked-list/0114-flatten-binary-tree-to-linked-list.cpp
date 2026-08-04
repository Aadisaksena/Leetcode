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
    void flatten(TreeNode* root) {
        flat(root);
    }
    void flat(TreeNode* root){
        if (root == nullptr) return;
        flat(root->left);
        flat(root->right);
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left = nullptr;
        //root->right->right=temp;
         TreeNode* curr = root->right;
    while (curr && curr->right)
        curr = curr->right;

    if (curr)
        curr->right = temp;
    else
        root->right = temp;
    }
};