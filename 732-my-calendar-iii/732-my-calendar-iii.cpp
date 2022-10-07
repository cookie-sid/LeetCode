class MyCalendarThree {
public:
    
    map<int,int> m;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        int sum = 0;
        int ans = 0;
        map<int,int> tmp;
        for(auto x : m) {
            sum += x.second;
            ans = max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */