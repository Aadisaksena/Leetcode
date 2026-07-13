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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
       vector<vector<int>> ans;

       queue<TreeNode*> q;
       q.push(root);
  

       while(!q.empty()){

        vector<int> level;
        int n=q.size();
        for(int i=0;i<n;i++){
           TreeNode* node=q.front();
           if(node->left!=NULL)
           q.push(node->left);
           if(node->right!=NULL)
           q.push(node->right);

           level.push_back(node->val);
           q.pop();
        }
        ans.push_back(level);
       }
       vector<vector<int>>finalans; 
       for(int i=0;i<ans.size();i++){
        if(i%2==0)
        finalans.push_back(ans[i]);
        else{
            finalans.push_back(reverse(ans[i]));
        }
       }


       return finalans; 

    }
    vector<int> reverse(vector<int>& v){
        int i=0,j=v.size()-1;
        while(i<=j){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
        return v;
    }
};