class MyCalendar {
public:
    
    vector<pair<int,int>> v;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ans = true;
        for(auto x : v) {
            if(((start >= x.first and start < x.second) or (end - 1 >= x.first and end - 1 < x.second))
              or ((x.first >= start and x.first < end) or (x.second - 1 >= start and x.second - 1 < end)))
                return false;
            if(!ans)
                break;
        }
        if(ans) {
            v.push_back(make_pair(start,end));
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */