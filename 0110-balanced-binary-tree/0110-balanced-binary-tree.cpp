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
    int check(TreeNode* root){
        if(!root) return 0;
        int left_h = check(root->left);
        int right_h = check(root->right);
        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1)  return -1;
		return max(left_h, right_h) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        if (check(root) == -1)  return false;
		return true;
    }
};