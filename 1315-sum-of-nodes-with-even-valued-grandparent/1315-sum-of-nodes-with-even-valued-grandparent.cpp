/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        int ans=solve(root,sum);
        return ans;
    }
    int solve(TreeNode* root,int& sum) {
        // ek root node hai .. uske grandchildren check kartee
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 0;
        
        
        if ((root->val) % 2 == 0) {

            if (root->left != NULL) {
                if (root->left->left != NULL)
                sum=sum+root->left->left->val;
                if (root->left->right != NULL)
                sum=sum+root->left->right->val;
            }
             if (root->right != NULL) {
                if (root->right->left != NULL)
                sum=sum+root->right->left->val;
                if (root->right->right != NULL)
                sum=sum+root->right->right->val;
            }
            
        }
        solve(root->right,sum);
        solve(root->left,sum);
        return sum;
    }
};