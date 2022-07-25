class myCmp {
    public:
    
    bool operator() (const pair<int,string> &p1, const pair<int,string> &p2) {
        if(p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

class FoodRatings {
public:
    
    map<string,string> f2C;
    map<string,int> cR;
    map<string,priority_queue<pair<int,string>, vector<pair<int,string>>, myCmp>> c2HR;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i= 0; i < foods.size(); i++) {
            f2C[foods[i]] = cuisines[i];
            cR[foods[i]] = ratings[i];
            c2HR[cuisines[i]].push(make_pair(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        if(cR[food] != newRating) {
            c2HR[f2C[food]].push(make_pair(newRating,food));
        }
        cR[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        while(!c2HR[cuisine].empty() and cR[c2HR[cuisine].top().second] != c2HR[cuisine].top().first) {
            c2HR[cuisine].pop();
        }
        return c2HR[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */