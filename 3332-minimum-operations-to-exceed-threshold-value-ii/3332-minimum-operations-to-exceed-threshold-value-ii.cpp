class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(auto &x : nums) q.push((long long)x);
        int ans = 0;
        while(q.top() < k){
            //  cout<<q.top()<<endl;
            long long x = 2*q.top();
            q.pop();
            x = x + q.top();
            q.pop();
            q.push(x);
            ans++;
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();