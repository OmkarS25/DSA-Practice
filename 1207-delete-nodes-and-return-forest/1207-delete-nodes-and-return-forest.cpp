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
    void helper(TreeNode* root, unordered_set<int>& to_delete_set, int isRoot, vector<TreeNode*>& res){
        if(!root) return;
        bool toDelete = to_delete_set.find(root->val) != to_delete_set.end();
        if (isRoot && !toDelete) res.push_back(root);
        if (root->left) {
            helper(root->left, to_delete_set, toDelete, res);
            if (to_delete_set.find(root->left->val) != to_delete_set.end()) {
                root->left = NULL;
            }
        }
        if (root->right) {
            helper(root->right, to_delete_set, toDelete, res);
            if (to_delete_set.find(root->right->val) != to_delete_set.end()) {
                root->right = NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        helper(root, to_delete_set, true, res);
        return res;
    }
};