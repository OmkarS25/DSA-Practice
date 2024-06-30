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
    void helper(TreeNode* root, unordered_map<int,int>& list, int &max_count){
        if(!root) return;
        list[root->val]++;
        max_count = max(max_count, list[root->val]);
        helper(root->left, list, max_count);
        helper(root->right, list, max_count);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> list;
        int max_count = 0;
        helper(root, list, max_count);
        vector<int> res;
        for(const auto & a : list){
            if(a.second == max_count)
                res.push_back(a.first);
        }
        return res;
    }
};