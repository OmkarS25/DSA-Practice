class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> st;
        for(auto & x: arr){
            st.insert(x);
        }
        int n = arr.size(), ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool find=true;
                int prev=arr[i], curr= arr[j], count=2;
                while(find){
                   if(st.find(curr+prev)!=st.end()){
                    int k= curr;
                    curr= curr+ prev;
                    prev=k;
                    count++;
                   }
                   else find=false;
                }
                ans=max(ans,count);
            }
        }
        if(ans==2) return 0;
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();