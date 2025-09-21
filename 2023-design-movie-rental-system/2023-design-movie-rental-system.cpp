class MovieRentingSystem {
private:
    struct MovieKey {
        int price, shop, movie;
        bool operator<(const MovieKey& a) const {
            if (price != a.price) return price < a.price;
            if (shop != a.shop) return shop < a.shop;
            return movie < a.movie;
        }
    };

    // price lookup: (shop,movie) -> price
    unordered_map<long long, int> priceMap;
    
    // unrented movies: movie -> set<(price, shop)>
    unordered_map<int, set<pair<int,int>>> available;
    
    // rented movies: global set<(price, shop, movie)>
    set<MovieKey> rented;
    
    long long key(int shop, int movie) {
        return ((long long)shop << 20) | movie;  // combine into single key
    }
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[key(shop,movie)] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto& s = available[movie];
        for (auto it = s.begin(); it != s.end() && res.size() < 5; ++it)
            res.push_back(it->second); // shop
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[key(shop,movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[key(shop,movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it)
            res.push_back({it->shop, it->movie});
        return res;
    }
};