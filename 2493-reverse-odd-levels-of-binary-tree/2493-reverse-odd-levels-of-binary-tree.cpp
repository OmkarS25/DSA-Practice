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
    void traverse(TreeNode* leftchild,TreeNode* rightchild,int level){
        if(leftchild==nullptr &&  rightchild==nullptr){//perfect binary tree
            return;
        }
        if(level%2==0){
            int temp=leftchild->val;
            leftchild->val=rightchild->val;
            rightchild->val=temp;
        }
        traverse(leftchild->left,rightchild->right,level+1);
        traverse(leftchild->right,rightchild->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(root->left,root->right,0);
        return root;

        // queue<TreeNode*> q;
        // q.push(root);
        // int level=1;
        // while(!q.empty()){
        //     vector<TreeNode*> currentlevel;
        //     int n=q.size();
        //     for(int i=0;i<n;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //         currentlevel.push_back(node);
        //     }
        //     if(level%2==0){
        //         int l=0;
        //         int r=currentlevel.size()-1;
        //         while(l<r){
        //             int temp=currentlevel[r]->val;
        //             currentlevel[r]->val=currentlevel[l]->val;
        //             currentlevel[l]->val=temp;
        //             l++;
        //             r--;
        //         }
        //     }
        //     level++;
        // }
        // return root;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();