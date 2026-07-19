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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
unordered_map<TreeNode*, unsigned long long> mp;

q.push(root);
mp[root] = 0;
int ans=1;

while (!q.empty()) {
    int n = q.size();

    unsigned long long mini = mp[q.front()];
    unsigned long long first, last;

    for (int i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();

        unsigned long long idx = mp[node] - mini;

        if (i == 0) first = idx;
        if (i == n - 1) last = idx;

        if (node->left) {
            mp[node->left] = 2 * idx + 1;
            q.push(node->left);
        }

        if (node->right) {
            mp[node->right] = 2 * idx + 2;
            q.push(node->right);
        }
    }

    ans = max(ans, (int)(last - first + 1));
}
return ans;
    }


    
};