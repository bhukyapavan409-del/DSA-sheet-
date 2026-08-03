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
    void find(TreeNode*root,int&cnt,int&ans,int k){
        if(root==NULL){
            return ;
        }
        //inorderd traversal
        find(root->left,cnt,ans,k);  // recursion 
        cnt++;
        if(cnt==k){
            ans=root->val;
            return ;
        }
        find(root->right,cnt,ans,k);
    }

     
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        find(root,cnt,ans,k);
        return ans;
        
    }
};