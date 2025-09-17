class FoodRatings {
public:
    struct Cmp {
        bool operator()(const auto& a, const auto& b) const {
            return (a.first != b.first) ? a < b : a.second > b.second;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp>> c2f;
    unordered_map<string, pair<string, int>> f2c;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = foods.size();
        for(int i = 0; i < n; ++i) {
            f2c[foods[i]] = {cuisines[i], ratings[i]};
            c2f[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        f2c[food].second = newRating;
        c2f[f2c[food].first].emplace(newRating, food);
    }
    
    string highestRated(string cuisine) {
        auto& pq = c2f[cuisine];
        while(pq.top().first != f2c[pq.top().second].second) {
            pq.pop();
        }
        return pq.top().second;
    }
};

// Used Hashmap and Ordered Set

// class FoodRatings {
// public:
//     // food -> (cuisine, rating)
//     unordered_map<string, pair<string,int>> foodInfo;
//     // cuisine -> ordered set of (-rating, foodName)
//     unordered_map<string, set<pair<int,string>>> cuisineFoods;

//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for (int i=0; i<foods.size(); ++i) {
//             foodInfo[foods[i]] = {cuisines[i], ratings[i]};
//             cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
//         }
//     }
    
//     void changeRating(string food, int newRating) {
//         string cuisine = foodInfo[food].first;
//         int oldRating = foodInfo[food].second;
//         foodInfo[food].second = newRating; // update rating
//         cuisineFoods[cuisine].erase({-oldRating, food}); // remove old pair
//         cuisineFoods[cuisine].insert({-newRating, food}); // insert new pair
//     }
    
//     string highestRated(string cuisine) {
//         return cuisineFoods[cuisine].begin()->second;
//     }
// };