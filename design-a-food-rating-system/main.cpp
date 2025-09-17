
class FoodRatings {
public:
    map<string, pair<int, string>> mp;
    map<string, set<pair<int, string>>> t;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string a = foods[i], b = cuisines[i];
            int c = ratings[i];
            mp[a] = make_pair(c, b);
            t[b].insert(pair<int, string>(-c, a));
        }
    }

    void changeRating(string food, int newRating) {
        pair<int, string> &p = mp[food];
        t[p.second].erase(make_pair(-p.first, food));
        p.first = newRating;
        t[p.second].insert(make_pair(-p.first, food));
    }

    string highestRated(string cuisine) {
        return t[cuisine].begin()->second;
    }
};
