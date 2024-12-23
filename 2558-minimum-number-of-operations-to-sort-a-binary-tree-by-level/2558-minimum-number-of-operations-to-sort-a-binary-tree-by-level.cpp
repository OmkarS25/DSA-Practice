class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal.
        while (!q.empty()) {
            int len = q.size();
            vector<int> level;

            // Traverse nodes at the current level.
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Count swaps needed to sort this level.
            ans += countSwaps(level);
        }

        return ans;
    }

private:
    int countSwaps(vector<int>& level) {
        int n = level.size();
        vector<int> sortedLevel(level);
        sort(sortedLevel.begin(), sortedLevel.end());
        unordered_map<int, int> indexMap;

        for (int i = 0; i < n; ++i) {
            indexMap[level[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (level[i] != sortedLevel[i]) {
                int correctIndex = indexMap[sortedLevel[i]];

                // Update the index map for the swapped elements.
                indexMap[level[i]] = correctIndex;
                indexMap[level[correctIndex]] = i;

                // Swap elements.
                swap(level[i], level[correctIndex]);
                swaps++;
            }
        }

        return swaps;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();