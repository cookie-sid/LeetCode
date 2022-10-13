class MaxStack {
public:
    
    stack<pair<int,int>> st;
    priority_queue<pair<int,int>> pq;
    map<int,int> m;
    
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(make_pair(x,m[x]));
        pq.push(make_pair(x,m[x]));
        m[x] += 1;
    }
    
    int pop() {
        while(!st.empty() and m[st.top().first] != st.top().second + 1) {
            st.pop();
        }
        auto tmp = st.top();
        st.pop();
        m[tmp.first] -= 1;
        return tmp.first;
    }
    
    int top() {
        while(!st.empty() and m[st.top().first] != st.top().second + 1) {
            st.pop();
        }
        return st.top().first;
    }
    
    int peekMax() {
        while(!pq.empty() and pq.top().second != m[pq.top().first] - 1) {
            pq.pop();
        }
        return pq.top().first;
    }
    
    int popMax() {
        while(!pq.empty() and pq.top().second != m[pq.top().first] - 1) {
            pq.pop();
        }
        auto tmp = pq.top();
        pq.pop();
        m[tmp.first] -= 1;
        while(!st.empty() and m[st.top().first] != st.top().second + 1) {
            st.pop();
        }
        return tmp.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */