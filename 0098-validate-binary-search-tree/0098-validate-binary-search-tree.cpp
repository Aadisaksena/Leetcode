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
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
    bool check(TreeNode* root, long long low, long long high){
        if(root==nullptr)return true;

 
        if(root->val>=high || root->val<=low)
        return false;

    

        bool left=check(root->left,low,root->val);
        bool right=check(root->right,root->val,high);

        return left && right;
    }
};