/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        map<TreeNode*, bool> vis;
        parent(root,mp);
        vector<int> ans;
        build(target,k,0,mp,vis,ans);
        return ans;
    }
    void build(TreeNode* root, int k, int dist,
               map<TreeNode*, TreeNode*>& parent, map<TreeNode*, bool>& vis,
               vector<int>& ans) {
        if (root == nullptr)
            return;

        if (vis[root])
            return;

        vis[root] = true;

        if (dist == k) {
            ans.push_back(root->val);
            return;
        }

        if (root->left)
            build(root->left, k, dist + 1, parent, vis, ans);

        if (root->right)
            build(root->right, k, dist + 1, parent, vis, ans);

        if (parent.count(root))
            build(parent[root], k, dist + 1, parent, vis, ans);
    }
    void parent(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr)
            return;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        parent(root->right, mp);
        parent(root->left, mp);
    }
};