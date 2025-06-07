/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root) return NULL;

//         if(p->val < root->val && q->val < root->val)
//             return lowestCommonAncestor(root->left, p, q);
//         else if(p->val > root->val && q->val > root->val)
//             return lowestCommonAncestor(root->right, p, q);
//         else return root;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root->val < p->val && root->val < q->val) root=root->right;
            else if(root->val > p->val && root->val > q->val) root=root->left;
            else return root;
        }
        return root;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();