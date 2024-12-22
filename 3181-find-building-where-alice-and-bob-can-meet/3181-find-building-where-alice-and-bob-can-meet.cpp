class Solution
{
public:
    class segtree
    {
        vector<long long> tree;
        vector<long long> v;
        long long sz;

        void build(long long crr, long long l, long long r)
        {
            if (l == r)
            {
                tree[crr] = v[l];
                return;
            }
            long long mid = (l + r) / 2;
            build(2 * crr + 1, l, mid);
            build(2 * crr + 2, mid + 1, r);
            tree[crr] = max(tree[2 * crr + 1], tree[2 * crr + 2]);
        }

    public:
        segtree(vector<int> &arr)
        {
            v = vector<long long>(arr.begin(), arr.end()); 
            sz = v.size();
            tree.resize(4 * sz + 1);
            build(0, 0, sz - 1);
        }

        long long qry(long long crr, long long l, long long r, long long s, long long e)
        {
            if (s > r || e < l) 
                return INT_MIN;
            if (l >= s && r <= e)
                return tree[crr];
            long long mid = (l + r) / 2;
            return max(qry(2 * crr + 1, l, mid, s, e), qry(2 * crr + 2, mid + 1, r, s, e));
        }
    };
    vector<int> leftmostBuildingQueries(vector<int> &v, vector<vector<int>> &q)
    {
        int n = v.size();
        segtree st(v);
        vector<int> ans(q.size());
        for (int i = 0; i < q.size(); i++)
        {
            int a = q[i][0], b = q[i][1];
            if (a > b)
                swap(a, b);
            int th = max(v[a], v[b]);
            if (v[a] < v[b] || a == b)
            {
                ans[i] = b;
                continue;
            }
            int l = b, r = n - 1;
            if (st.qry(0, 0, n - 1, b, n - 1) <= th)
            {
                ans[i] = (-1);
                continue;
            }
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int qq = st.qry(0, 0, n - 1, b, mid);
                if (qq > th)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            if (v[l] <= th)
                ans[i] = (-1);
            else
                ans[i] = l;
        }
        return ans;
    }
};\

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();