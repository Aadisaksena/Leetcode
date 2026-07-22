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
    void makeParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        if (root == nullptr)
            return;

        if (root->left) {
            parent[root->left] = root;
            makeParent(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            makeParent(root->right, parent);
        }
    }

    TreeNode* findStart(TreeNode* root, int start) {
        if (root == nullptr)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* left = findStart(root->left, start);
        if (left)
            return left;

        return findStart(root->right, start);
    }

    void dfs(TreeNode* root,
             int dist,
             map<TreeNode*, TreeNode*>& parent,
             map<TreeNode*, bool>& vis,
             int& ans) {

        if (root == nullptr)
            return;

        if (vis[root])
            return;

        vis[root] = true;

        ans = max(ans, dist);

        if (root->left)
            dfs(root->left, dist + 1, parent, vis, ans);

        if (root->right)
            dfs(root->right, dist + 1, parent, vis, ans);

        if (parent.count(root))
            dfs(parent[root], dist + 1, parent, vis, ans);
    }

    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);

        TreeNode* startNode = findStart(root, start);

        map<TreeNode*, bool> vis;
        int ans = 0;

        dfs(startNode, 0, parent, vis, ans);

        return ans;
    }
};