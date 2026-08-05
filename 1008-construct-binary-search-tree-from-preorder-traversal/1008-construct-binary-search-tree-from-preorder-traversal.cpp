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
    // optimized 
    TreeNode* insertInBst(TreeNode* root, int min, int max, int val){
        if(!root){
            return new TreeNode(val);
        }

        if(root->val>=min && root->val <= max){
            if(val < root->val){
                root->left = insertInBst(root->left, min, root->val, val);
            }
            else{
                root->right = insertInBst(root->right, root->val, max, val);
            }
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            insertInBst(root, INT_MIN, INT_MAX, preorder[i]);
        }
        return root;
    }
};