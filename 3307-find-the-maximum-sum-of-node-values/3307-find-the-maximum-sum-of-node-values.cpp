class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> deltas(n); // represents how will change number after XOR
        for (int i = 0; i < n; i++) {
            deltas[i] = (nums[i] ^ k) - nums[i];
        }
        sort(deltas.rbegin(), deltas.rend());

        long long res = 0;
        for (int num : nums) {
            res += num;
        }

        for (int startInd = 0; startInd < n - 1; startInd += 2) {
            long long changingDelta = deltas[startInd] + deltas[startInd + 1]; // showing whether if would be beneficial if we XOR this two nodes 
            if (changingDelta > 0) {
                res += changingDelta;
            } else {
                break;
            }
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

// which edges have the maximun sum without repeating the edge.
// and then just add add the nums array in which the values where changed.
// testcases:-
// [24,78,1,97,44]
// 6
// [[0,2],[1,2],[4,2],[3,4]]
// (https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/5176804/extreme-detailed-explanation-that-could-ever-exists)
// Another solution.(https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/5177609/detailed-explanation-2-approaches-extremely-simple-and-effective)
// class Solution {
// public:
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         int n = nums.size();
//         vector<vector<long long>> temp(n, vector<long long>(2, -1)); // temp[current_index(node)][is_even]
        
//         return calculateMax(nums, n, k, 0, 1, temp);
//     }

// private:
//     // calculate_max -> cur_ind -> cur_index of the tree and is_even represents whether we have already changed (XOR) even or odd number of nodes 
//     long long calculateMax(vector<int>& nums, int n, int k, int curInd, int isEven, vector<vector<long long>>& temp) {
//         if (curInd == n) {  // if we go to node which doesn't exist
//             return isEven == 1 ? 0 : LLONG_MIN;
//         }
//         if (temp[curInd][isEven] != -1) {  // if we've already encountered this state
//             return temp[curInd][isEven];
//         }

//         // checking all possible variants (no XOR or XOR)
//         long long noXor = nums[curInd] + calculateMax(nums, n, k, curInd + 1, isEven, temp);  // we don't change the number of XOR nodes
//         long long withXor = (nums[curInd] ^ k) + calculateMax(nums, n, k, curInd + 1, !isEven, temp);  // we added 1 XORed node

//         long long mxPossible = max(noXor, withXor);
//         temp[curInd][isEven] = mxPossible;
//         return mxPossible;
//     }
// };

