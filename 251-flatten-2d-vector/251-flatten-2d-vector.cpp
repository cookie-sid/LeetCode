class Vector2D {
public:
    
    vector<vector<int>> v;
    int x = 0, y = 0;
    
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
    }
    
    int next() {
        while(v[x].size() == y) {
            x++;
            y = 0;
        }
        int res = v[x][y];
        y++;
        while(x < v.size() and v[x].size() == y) {
            x++;
            y = 0;
        }
        return res;
    }
    
    bool hasNext() {
        while(x < v.size() and v[x].size() == y) {
            x++;
            y = 0;
        }
        return !(x == v.size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */