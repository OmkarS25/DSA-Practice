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
    int helper(TreeNode* root, int count){
        if(!root) return INT_MAX;
        count++;
        if(!root->left && !root->right){
            return count;
        }
        return min((helper(root->left, count)), (helper(root->right, count)));
    }
    int minDepth(TreeNode* root) {
       if(!root) return 0;
       return helper(root, 0); 
    }
};