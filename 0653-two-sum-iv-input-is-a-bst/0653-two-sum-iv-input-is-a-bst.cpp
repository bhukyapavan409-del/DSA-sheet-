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
 class BstIterator{
    stack<TreeNode*>mystack;
    bool reverse=true;
public:
BstIterator(TreeNode*root,bool isreverse){
    reverse=isreverse;
    pushAll(root);
}
bool hasnext(){
    return !mystack.empty();   //0 next smallest 
}
int next(){
    TreeNode*tempnode=mystack.top();
    mystack.pop();
    if(!reverse){
        pushAll(tempnode->right);
    }
    else{
        pushAll(tempnode->left);
    }
    return tempnode->val;
}

void pushAll(TreeNode*node){
    for(;node!=NULL;){
        mystack.push(node);
        if(reverse==true){
            node=node->right;
        }else{
            node=node->left;
        }
    }
  }
};


class Solution {

public:

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BstIterator l(root,false);   // next means false (l)
        BstIterator r(root,true);    // before means true(r)
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};