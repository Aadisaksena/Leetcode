class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    int bs(vector<int>& v, int x) {
        int l = 0;
        int r = v.size() - 1;
        int ans = v.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (v[mid] >= x) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(root, v);

        vector<vector<int>> ans;

        for (int q : queries) {
            int i = bs(v, q);

            int small = -1;
            int large = -1;

            if (i < v.size())
                large = v[i];

            if (i > 0)
                small = v[i - 1];

            if (i < v.size() && v[i] == q)
                small = large = q;

            ans.push_back({small, large});
        }

        return ans;
    }
};