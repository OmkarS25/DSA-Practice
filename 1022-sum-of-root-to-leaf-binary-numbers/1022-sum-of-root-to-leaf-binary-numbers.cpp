class Solution {
public:
    int helper(TreeNode* root, string num) {
        if (!root) return 0;
        num += to_string(root->val);
        if (!root->left && !root->right) return stoi(num, nullptr, 2);
        return helper(root->left, num) + helper(root->right, num);
    }
    int sumRootToLeaf(TreeNode* root) { return helper(root, ""); }
};