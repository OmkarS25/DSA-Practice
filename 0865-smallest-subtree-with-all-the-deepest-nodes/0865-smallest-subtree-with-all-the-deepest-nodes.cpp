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
    int cal_depth(TreeNode* root){
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == NULL){
                depth++;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if (temp->left != NULL){
                    q.push(temp->left);
                }
                if (temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        return depth;
    }
    TreeNode* dfs(TreeNode* root, int depth){
        // Base Case
        if(!root || depth == 1 || depth == 0) return root;

        // Ek case mei solve karunga
        TreeNode* left = dfs(root->left, depth-1);
        TreeNode* right = dfs(root->right, depth-1);
        if(left && right) return root; // If both are not null
        return left ? left : right; // If both are null
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = cal_depth(root);
        return dfs(root, depth);
    }
};