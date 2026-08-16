class MovieRentingSystem {
    map<pair<int, int>, int> shopMoviePrices; // (shop, movie) -> price
    unordered_map<int, set<pair<int, int>>> unrentedMovieInventory; // movie -> set of (price, shop)
    set<tuple<int, int, int>> rentedMoviesSet; // (price, shop, movie)

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            shopMoviePrices[{shop, movie}] = price;
            unrentedMovieInventory[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> topShops;
        auto it = unrentedMovieInventory.find(movie);
        if (it != unrentedMovieInventory.end()) {
            int count = 0;
            for (const auto& [price, shop] : it->second) {
                topShops.push_back(shop);
                if (++count == 5) break;
            }
        }
        return topShops;
    }

    void rent(int shop, int movie) {
        int price = shopMoviePrices[{shop, movie}];
        unrentedMovieInventory[movie].erase({price, shop});
        rentedMoviesSet.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = shopMoviePrices[{shop, movie}];
        rentedMoviesSet.erase({price, shop, movie});
        unrentedMovieInventory[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> reportList;
        int count = 0;
        for (const auto& [price, shop, movie] : rentedMoviesSet) {
            reportList.push_back({shop, movie});
            if (++count == 5) break;
        }
        return reportList;
    }
};
