class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;      
        queue<TreeNode*> q;         
        q.push(root);               
        while (!q.empty()) {
            int n = q.size();      
            long long sum = 0;     
            while (n--) {
                TreeNode* node = q.front(); q.pop();  
                sum += (long long)node->val;           
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum);
        }
        if (k > res.size()) return -1;
        sort(res.begin(), res.end(), greater<long long>());
        return res[k-1];
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();