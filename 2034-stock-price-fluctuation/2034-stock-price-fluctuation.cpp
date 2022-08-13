class StockPrice {
public:
    
    map<int,int> m;
    priority_queue<pair<int,int>> maxi,mini;
    int latestTS = -1, latestPrice = -1;
        
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        m[timestamp] = price;
        maxi.push(make_pair(price,timestamp));
        mini.push(make_pair(-price,timestamp));
        if(timestamp >= latestTS) {
            latestTS = timestamp;
            latestPrice = price;
        }
    }
    
    int current() {
        return latestPrice;
    }
    
    int maximum() {
        while(m[maxi.top().second] != maxi.top().first) {
            maxi.pop();
        }
        return maxi.top().first;
    }
    
    int minimum() {
        while(m[mini.top().second] != -mini.top().first) {
            mini.pop();
        }
        return -mini.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */