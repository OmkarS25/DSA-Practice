class Solution {
    class SegmentTree {
    public:
        vector<int> tree;
        int n;

        SegmentTree(const vector<int>& arr) {
            n = arr.size();
            tree.resize(4 * n, 1);
            build(0, 0, n - 1, arr);
        }

        void build(int node, int start, int end, const vector<int>& arr) {
            if (start == end) {
                tree[node] = 1;  // Single element is always "special"
                return;
            }
            int mid = start + (end - start) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);

            // Combine results for the current segment
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
            if ((arr[mid] & 1) == (arr[mid + 1] & 1)) {
                tree[node] = 0;  // Breaks "special" property at boundary
            }
        }

        int query(int node, int start, int end, int left, int right, const vector<int>& arr) {
            if (start > right || end < left) {
                return 1;  // Neutral value for "AND" operation
            }
            if (start >= left && end <= right) {
                return tree[node];
            }

            int mid = start + (end - start) / 2;
            int leftQuery = query(2 * node + 1, start, mid, left, right, arr);
            int rightQuery = query(2 * node + 2, mid + 1, end, left, right, arr);
            int result = leftQuery & rightQuery;

            // Check the boundary if it overlaps
            if (left <= mid && right > mid) {
                if ((arr[mid] & 1) == (arr[mid + 1] & 1)) {
                    result = 0;
                }
            }
            return result;
        }

        bool isSpecial(int left, int right, const vector<int>& arr) {
            return query(0, 0, n - 1, left, right, arr);
        }
    };

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree st(nums);
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(st.isSpecial(query[0], query[1], nums));
        }
        return result;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();