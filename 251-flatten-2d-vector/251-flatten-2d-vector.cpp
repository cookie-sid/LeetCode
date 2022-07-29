class Vector2D {
public:
    
    vector<int> v;
    int ptr = 0;
    
    Vector2D(vector<vector<int>>& vec) {
        for(auto x : vec) {
            for(auto y : x) {
                v.push_back(y);
            }
        }
    }
    
    int next() {
        return v[ptr++];
    }
    
    bool hasNext() {
        return ptr != v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */