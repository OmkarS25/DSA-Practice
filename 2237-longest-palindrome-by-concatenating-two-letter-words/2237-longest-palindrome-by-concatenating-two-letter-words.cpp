class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>store;
        unordered_set<string>used;
        int ans=0;
        bool took=false;

        for(auto&x:words){
            store[x]++;
        }
        
        for(auto&x:store){
            // cout<<x.first<<"  "<< x.second<<endl;
            if(x.first[0]==x.first[1]){
                if(x.second&1) took=true;
                ans+=(x.second/2)*4;
            }
            else if(used.find(x.first)==used.end()){
                string older=x.first;
                string newer=older;
                reverse(newer.begin(),newer.end());

                if(store.find(newer)!=store.end()){
                    ans=ans+(min(store[older],store[newer]))*4;   
                    used.insert(newer);
                }

            }
        }
        return (took) ? ans+2 : ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();