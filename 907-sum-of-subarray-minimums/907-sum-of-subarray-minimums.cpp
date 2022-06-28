class Solution {
public:
    
    // 2 3 5 1 2 7 5 3 4 6
    
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        long long ans = 0, mod = 1e9 + 7, mini = 1e9;
        vector<long long> left(n,1);
        vector<long long> right(n,1);
        for(int i = 0; i < arr.size(); i++) {
            mini = min(mini,(long long)arr[i]);
            while(st.top() != -1 and arr[st.top()] > arr[i]) {
                right[st.top()] = i - st.top();
                st.pop();
            }
            left[i] = i - st.top();
            st.push(i);
        }
        int p = arr.size();
        while(st.top() != -1) {
            right[st.top()] = p - st.top();
            st.pop();
        }
        for(int i = 0; i < n; i++) {
            
            ans += left[i] * right[i] * arr[i];
            ans %= mod;
        }
        return ans;
    }
};