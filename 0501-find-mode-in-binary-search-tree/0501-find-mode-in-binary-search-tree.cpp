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
    map<int, int> freq;
  void traverse(TreeNode* root) {
        if (root == NULL)
            return;
     freq[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
  vector<int> findMode(TreeNode* root) {
        traverse(root);
        int maxFreq = 0;
     for (auto it : freq) {
            maxFreq = max(maxFreq, it.second);
        }
        vector<int> ans;
        for (auto it : freq) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};