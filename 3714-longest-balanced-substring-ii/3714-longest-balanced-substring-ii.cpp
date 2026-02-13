class Solution {
public:
    // For hashing pair in map 
    struct pair_hash{
        size_t operator()(const pair<int,int>&p) const{
            return hash<int>()(p.first)^(hash<int>()(p.second)<<1);
        }
    };

    // Two distinct
    int twodistinct(const string& s, char c1, char c2){
        map<int, int> pos;
        pos[0] = -1;
        int ans = 0;
        int delta = 0;
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] != c1 && s[i] != c2){
                pos.clear();
                pos[0] = i;
                delta = 0;
                continue;
            }
            if(s[i] == c1)
                delta++;
            else
                delta--;
            if(pos.find(delta) != pos.end()){
                ans = max(ans, i - pos[delta]);
            }
            else
                pos[delta] = i;
        }
        return ans;
    }

    // Main function
    int longestBalanced(string s) {
        int mx=1,i,j=0,n=s.size();

        // Single char
        for(i=0;i<n-1;i++){
            char ch=s[i];
            j=i;
            while(i<n&&s[i]==ch)
                i++;
            mx=max(i-j,mx);
            i--;
        }

        // Two distinct
        int zz=max(twodistinct(s,'a','b'),twodistinct(s,'b','c'));
        zz=max(zz,twodistinct(s,'a','c'));
        mx=max(zz,mx);

        // All three char
        unordered_map<pair<int,int>,int,pair_hash>mp;
        int cnb=0,cna=0,cnc=0;
        mp[{0,0}]=-1;
        for(i=0;i<n;i++){
            if(s[i]=='a') cna++;
            else if(s[i]=='b') cnb++;
            else cnc++;

            if(mp.find({cnb-cna,cnc-cna})!=mp.end()){
                mx=max(mx,i-mp[{cnb-cna,cnc-cna}]);
            }
            else mp[{cnb-cna,cnc-cna}]=i;
        }

        return mx;
    }
};