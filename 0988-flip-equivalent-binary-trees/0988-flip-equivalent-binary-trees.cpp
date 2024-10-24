class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checker(root1, root2);
    }

    bool checker(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2 || node1->val != node2->val) return false;

        return (checker(node1->left, node2->left) || checker(node1->left, node2->right)) &&
               (checker(node1->right, node2->right) || checker(node1->right, node2->left));
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();