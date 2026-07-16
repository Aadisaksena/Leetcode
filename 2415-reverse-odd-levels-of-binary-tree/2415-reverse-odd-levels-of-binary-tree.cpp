class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> nodes;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse values at odd levels
            if (level % 2 == 1) {
                int i = 0, j = nodes.size() - 1;
                while (i < j) {
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};