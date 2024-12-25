class Solution {
public:
    vector<int> arr;
    void preOrder(TreeNode* Node,  int level){
        if (Node== NULL) return;
        if (arr.size()<=level) arr.push_back(INT_MIN);
        arr[level]=max(arr[level], Node->val);

        preOrder(Node->left, level+1);
        preOrder(Node->right, level+1);     
    }

    vector<int> largestValues(TreeNode* root) {
        if (root==NULL) return {};
        preOrder(root, 0);
        return arr;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();