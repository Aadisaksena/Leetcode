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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if (node == nullptr)
        break;

    count++;
    q.push(node->left);
    q.push(node->right);
}
return count;
    }
    
};