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
class FindElements {
public:
    set<int>ele;
    void Recover(TreeNode* root)
    {
        if(root==nullptr)
        return;
        if(root->left!=NULL){
        root->left->val=(2*(root->val))+1;
        ele.insert((2*(root->val))+1);
        Recover(root->left);}
        if(root->right!=NULL){
        root->right->val=(2*(root->val))+2;
        ele.insert((2*(root->val))+2);
        Recover(root->right);}
    }
    FindElements(TreeNode* root) {
        root->val=0;
        ele.insert(root->val);
        Recover(root);
    }
    
    bool find(int target) {
        if(ele.find(target)!=ele.end())
        return true;
        return false;
    }

};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

 #pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();