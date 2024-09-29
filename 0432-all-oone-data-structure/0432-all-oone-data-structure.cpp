#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class AllOne {
    unordered_map<string, int> map;
public:
    AllOne() {}
    
    void inc(string key) { 
        if(map[key] == -1) this->map[key] = 1;
        else this->map[key]++; 
    }
    
    void dec(string key) {
        this->map[key]--;
        if(!map[key]) map[key] = -1;
    }
    
    string getMaxKey() {
        int max = INT_MIN;
        string res = "";
        for(auto & pair : map){
            if(pair.second > max && pair.second > 0){
                max = pair.second;
                res = pair.first;
            }
        }
        return res;
    }
    
    string getMinKey() {
        int min = INT_MAX;
        string res = "";
        for(auto & pair : map){
            if(pair.second < min && pair.second > 0){
                min = pair.second;
                res = pair.first;
            }
        }
        return res;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */