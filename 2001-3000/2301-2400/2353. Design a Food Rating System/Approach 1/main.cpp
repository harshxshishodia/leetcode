class FoodRatings {
    unordered_map<string, pair<string, int>> foodDetails; // food -> (cuisine, rating)
    unordered_map<string, set<pair<int, string>>> cuisineRatingsMap; // cuisine -> set of (-rating, food)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < static_cast<int>(foods.size()); i++) {
            foodDetails[foods[i]] = {cuisines[i], ratings[i]};
            cuisineRatingsMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto& [cuisine, currentRating] = foodDetails[food];
        cuisineRatingsMap[cuisine].erase({-currentRating, food});
        currentRating = newRating;
        cuisineRatingsMap[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineRatingsMap[cuisine].begin()->second;
    }
};
