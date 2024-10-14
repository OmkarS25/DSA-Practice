#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long int res = 0;
        for(int i=0; i<k; i++){
            const int top = pq.top();
            res += top;
            if(top == 1){
                res += (k-1-i);
                break;
            }
            pq.pop();
            pq.push((top+2) / 3);
        }
        return res;
    }
};

// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {
//         make_heap(nums.begin(), nums.end());
//         long long score=0;
//         for(int i=0; i<k; i++){
//             pop_heap(nums.begin(), nums.end());
//             int x=nums.back();
//             score+=x;
//             if (x==1){
//                 score+=(k-1-i);
//                 break;
//             }
//             nums.back()=(x+2)/3;
//             push_heap(nums.begin(), nums.end());
//         }
//         return score;
//     }
// };