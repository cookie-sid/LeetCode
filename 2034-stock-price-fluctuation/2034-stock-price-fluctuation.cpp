class StockPrice {
public:
    
    int currTS = 0, currPrice = -1;
    unordered_map<int,int> m;
    priority_queue<pair<int,int>> pq_max, pq_min;
    
    StockPrice() {
    }
    
    void update(int ts, int price) {
        m[ts] = price;
        pq_min.push(make_pair(-price,ts));
        pq_max.push(make_pair(price,ts));
        if(ts >= currTS) {
            currTS = ts;
            currPrice = price;
        }
    }
    
    int current() {
        return currPrice;
    }
    
    int maximum() {
        while(m[pq_max.top().second] != pq_max.top().first) {
            pq_max.pop();
        }
        return pq_max.top().first;
    }
    
    int minimum() {
        
        while(m[pq_min.top().second] != -pq_min.top().first) {
            pq_min.pop();
        }
        return -pq_min.top().first;
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