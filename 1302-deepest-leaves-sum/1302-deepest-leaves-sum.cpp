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
    int deepestLeavesSum(TreeNode* root) {
      int maxde= maxdepth(root); 
      int ans=solve(root,1,maxde);
      return ans;
    }
    int solve(TreeNode* root, int depth,int maxdepth){
        if(root==NULL)
        return 0;
        if(depth==maxdepth){
            return root->val;
        }
        int sum=solve(root->left,depth+1,maxdepth)+solve(root->right,depth+1,maxdepth);

        return sum;
    }
    int maxdepth(TreeNode* root){
        if(root==NULL)
        return 0;
        int left=1+maxdepth(root->left);
        int right=1+maxdepth(root->right);

        return max(left,right);
    }
};