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
class FindElements {
public:
TreeNode* root;
    FindElements(TreeNode* root) {
        this->root=root;
       root->val=0;
       recover(root);
    }
    void recover(TreeNode* root){
        if(root==nullptr)return;
        if(root->left)
        root->left->val=root->val*2 + 1;
        if(root->right)
        root->right->val=root->val*2 + 2;
        recover(root->left);
        recover(root->right);
    }
    
    bool find(int target) {
        bool ans=findd(target,root);
        return ans;
    }
    bool findd(int target,TreeNode* root){
        if(root==nullptr)return false;
        if(root->val==target)return true;
        

        bool ans=findd(target,root->left) || findd(target,root->right);
        return ans;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */