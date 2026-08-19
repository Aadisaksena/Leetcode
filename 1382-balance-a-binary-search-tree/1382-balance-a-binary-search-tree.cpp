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
        vector<int> inorder;
    TreeNode* balanceBST(TreeNode* root) {
        inorder_traversal(root);
        return balanced(inorder,0,inorder.size()-1);

    }
    TreeNode* balanced(vector<int>& inorder, int start, int end){

        if (start > end)
        return NULL;
        
        int mid=(end+start)/2;
        TreeNode* root=new TreeNode(inorder[mid]);

  

        root->left=balanced(inorder,start,mid-1);
        root->right=balanced(inorder,mid+1,end);

        return root;
    }
    void inorder_traversal(TreeNode* root){
        if(root==nullptr)
        return;

        inorder_traversal(root->left);
        inorder.push_back(root->val);
        inorder_traversal(root->right);
    }
};