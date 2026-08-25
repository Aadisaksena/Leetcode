class Solution {
public:
    vector<int> a, b, ans;

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1, a);
        inorder(root2, b);

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    void inorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};