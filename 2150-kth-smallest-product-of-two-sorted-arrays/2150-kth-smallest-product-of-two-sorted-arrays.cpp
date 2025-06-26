#define ll long long
class Solution {
public:
    ll floorDiv(ll a, ll b) {
        if (b == 0) return 1e18;
        ll q = a / b;
        if ((a ^ b) < 0 && a % b != 0) q--;
        return q;
    }

    ll ceilDiv(ll a, ll b) {
        if (b == 0) return 1e18;
        ll q = a / b;
        if ((a ^ b) > 0 && a % b != 0) q++;
        return q;
    }

    ll countLessEqual(vector<int>& A, vector<int>& B, ll mid) {
        ll count = 0;
        int m = B.size();

        for (ll a : A) {
            if (a > 0) {
                ll bound = floorDiv(mid, a);
                count += upper_bound(B.begin(), B.end(), bound) - B.begin();
            } else if (a < 0) {
                ll bound = ceilDiv(mid, a);
                count += B.end() - lower_bound(B.begin(), B.end(), bound);
            } else { // a == 0
                if (mid >= 0) count += m;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        ll low = -1e10, high = 1e10;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();