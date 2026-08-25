class Solution {
public:
    int maxsum = 0;

    bool helper(TreeNode* root, int& sum, int& mn, int& mx) {
        if (!root) {
            sum = 0;
            mn = INT_MAX;
            mx = INT_MIN;
            return true;
        }

        int lsum, lmn, lmx;
        int rsum, rmn, rmx;

        bool left = helper(root->left, lsum, lmn, lmx);
        bool right = helper(root->right, rsum, rmn, rmx);

        if (left && right && lmx < root->val && root->val < rmn) {
            sum = lsum + rsum + root->val;
            mn = min(lmn, root->val);
            mx = max(rmx, root->val);

            maxsum = max(maxsum, sum);

            return true;
        }

        return false;
    }

    int maxSumBST(TreeNode* root) {
        int sum, mn, mx;
        helper(root, sum, mn, mx);
        return maxsum;
    }
};