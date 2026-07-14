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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum,0);
    }
    bool check(TreeNode* root, int& targetSum,int sum){
        //leaf check
        if(root==NULL)return false;
        if(root->left==NULL && root->right==NULL){
           if(sum+root->val==targetSum)
           return true;
           return false;
        }
       return check(root->left,targetSum, sum+root->val) || check(root->right,targetSum, sum+root->val);

    }
};