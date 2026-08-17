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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);
    }
    TreeNode* find(TreeNode* &root, TreeNode* &p, TreeNode* &q){
        if(root==nullptr)
        return nullptr;
        if(root->val>q->val && root->val>p->val){
            return find(root->left,p,q);
        }
        else if(root->val<q->val && root->val<p->val){
            return find(root->right,p,q);
        }
        //root is found
        TreeNode* ans=root;
        return ans;
    }
};