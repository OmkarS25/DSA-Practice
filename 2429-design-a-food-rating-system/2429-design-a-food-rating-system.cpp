class FoodRatings {
public:
    // food -> (cuisine, rating)
    unordered_map<string, pair<string,int>> foodInfo;
    // cuisine -> ordered set of (-rating, foodName)
    unordered_map<string, set<pair<int,string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); ++i) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodInfo[food].first;
        int oldRating = foodInfo[food].second;
        foodInfo[food].second = newRating; // update rating
        cuisineFoods[cuisine].erase({-oldRating, food}); // remove old pair
        cuisineFoods[cuisine].insert({-newRating, food}); // insert new pair
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};