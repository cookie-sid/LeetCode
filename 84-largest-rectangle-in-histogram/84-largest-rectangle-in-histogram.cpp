class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = -1;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < heights.size(); i++) {
            ans = max(ans,heights[i]);
            
            
            while(st.top() != -1 and heights[st.top()] > heights[i]) {
                int popped = st.top();
                st.pop();
                ans = max(ans,(i - st.top() - 1) * heights[popped]);
            }
            st.push(i);
        }
        int last = heights.size();
        while(st.top() != -1) {
            int popped = st.top();
            st.pop();
            ans = max(ans,(last - st.top() - 1)*heights[popped]);
        }
        return ans;
    }
};