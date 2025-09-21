class MovieRentingSystem {
private:
    // movie -> set of {price, shop} for unrented
    map<int, set<pair<int, int>>> unrentedMovies;
    
    // set of {price, shop, movie} for rented
    set<tuple<int, int, int>> rentedMovies;
    
    // price lookup
    map<pair<int, int>, int> prices;
    
public:
    /**
     * Initialize system
     * TC: O(E log E), SC: O(E)
     */
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            
            unrentedMovies[movie].insert({price, shop});
            prices[{shop, movie}] = price;
        }
    }
    
    /**
     * Search cheapest 5 shops
     * TC: O(1), SC: O(1)
     */
    vector<int> search(int movie) {
        vector<int> result;
        
        if (unrentedMovies.find(movie) != unrentedMovies.end()) {
            auto it = unrentedMovies[movie].begin();
            while (it != unrentedMovies[movie].end() && result.size() < 5) {
                result.push_back(it->second); // shop
                ++it;
            }
        }
        
        return result;
    }
    
    /**
     * Rent movie
     * TC: O(log n), SC: O(1)
     */
    void rent(int shop, int movie) {
        int price = prices[{shop, movie}];
        
        // Remove from unrented
        unrentedMovies[movie].erase({price, shop});
        
        // Add to rented
        rentedMovies.insert({price, shop, movie});
    }
    
    /**
     * Drop movie
     * TC: O(log n), SC: O(1)
     */
    void drop(int shop, int movie) {
        int price = prices[{shop, movie}];
        
        // Remove from rented
        rentedMovies.erase({price, shop, movie});
        
        // Add back to unrented
        unrentedMovies[movie].insert({price, shop});
    }
    
    /**
     * Report cheapest 5 rented
     * TC: O(1), SC: O(1)
     */
    vector<vector<int>> report() {
        vector<vector<int>> result;
        
        auto it = rentedMovies.begin();
        while (it != rentedMovies.end() && result.size() < 5) {
            result.push_back({get<1>(*it), get<2>(*it)}); // shop, movie
            ++it;
        }
        
        return result;
    }
};