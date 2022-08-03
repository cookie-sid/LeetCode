class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(end);
        
        if(it == m.begin()) {
            m[start] = end;
            return true;
        }
        else {
            it--;
            if((*it).second <= start) {
                m[start] = end;
                return true;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */