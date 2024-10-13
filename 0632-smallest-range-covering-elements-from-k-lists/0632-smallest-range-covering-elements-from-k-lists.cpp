#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
private:
    bool chk(int a,int b, int c, int d){
        if(b-a < d-c) return true;
        else if(b-a == d-c) if(a<c) return true;
        return false;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        int ansx = -1e5, ansy = 1e5, total_list = a.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<total_list;i++){
            for(int j=0;j<a[i].size();j++){
                vp.push_back({a[i][j],i});
            }
        }
        sort(vp.begin(), vp.end());
        unordered_map<int,int> um;
        int l=0, r=0, n = vp.size();
        while(r<n){
            int num = vp[r].first, list = vp[r].second;
            um[list]++;
            while(um.size() >= total_list){
                if(chk(vp[l].first,vp[r].first,   ansx, ansy )){
                    ansx = vp[l].first;
                    ansy = vp[r].first;
                }
                int old_list = vp[l].second;
                um[old_list]--;
                l++;
                if(um[old_list]==0) um.erase(old_list);
            }
            r++;
        }
        return {ansx, ansy};
    }
};