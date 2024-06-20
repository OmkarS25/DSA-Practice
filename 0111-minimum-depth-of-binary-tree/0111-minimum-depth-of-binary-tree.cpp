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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (right == 0 || left == 0)
            return max (left, right) + 1;
        root->left = nullptr;
        root->right = nullptr;
        return min(left, right) + 1;
    }
};


// MY Code
// class Solution {
// public:
//     int helper(TreeNode* root, int count){
//         if(!root) return INT_MAX;
//         count++;
//         if(!root->left && !root->right){
//             return count;
//         }
//         return min((helper(root->left, count)), (helper(root->right, count)));
//     }
//     int minDepth(TreeNode* root) {
//        if(!root) return 0;
//        return helper(root, 0); 
//     }
// };