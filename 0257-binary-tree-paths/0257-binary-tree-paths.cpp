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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path;
        solve(paths,path,root);
        return paths;
    }
    void solve(vector<string>& paths, string path, TreeNode* root){
        //if it is a leaf node
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            path.append(to_string(root->val));
            paths.push_back(path);
            return;
        }
        
        path.append(to_string(root->val));
        path.push_back('-');
        path.push_back('>');

        solve(paths,path,root->left);
        solve(paths,path,root->right);
    }

};