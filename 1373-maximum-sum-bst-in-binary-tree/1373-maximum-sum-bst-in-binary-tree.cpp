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
class NodeValue{
public:
     int maxNode;
     int minNode;
     int sum;
     NodeValue(int minNode,int maxNode,int sum){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->sum=sum;
     }
};

class Solution{
 private:
 int ans=0;
   NodeValue maxSumBstHelper(TreeNode*root){
    if(root==NULL){
        return NodeValue(INT_MAX,INT_MIN,0);
    }


    auto left=maxSumBstHelper(root->left);
    auto right=maxSumBstHelper(root->right);

if(left.maxNode < root->val && root->val<right.minNode){
    int currsum=left.sum+right.sum+root->val;
    ans=max(ans,currsum);

    return NodeValue(
        min(root->val,left.minNode),
        max(root->val,right.maxNode),
        currsum
    );
}
return  NodeValue(INT_MIN,INT_MAX,0);

   }
public:
 int maxSumBST(TreeNode* root){
    maxSumBstHelper(root);
    return ans;
        
    }
};