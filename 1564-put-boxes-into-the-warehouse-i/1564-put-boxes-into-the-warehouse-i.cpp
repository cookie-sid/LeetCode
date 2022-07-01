class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        stack<pair<int,int>> st;
        int n = warehouse.size();
        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                st.push(make_pair(warehouse[i],1));
            }
            else {
                if(warehouse[i] > st.top().first) {
                    st.push(make_pair(warehouse[i],1));
                }
                else {
                    int num = 0;
                    while(!st.empty() and st.top().first >= warehouse[i]) {
                        num += st.top().second;
                        st.pop();
                    }
                    st.push(make_pair(warehouse[i],num+1));
                }
            }
        }
        sort(boxes.rbegin(),boxes.rend());
        n = boxes.size();
        int ans = 0;
        for(int i = 0; i < n and !st.empty(); i++) {
            if(st.top().first >= boxes[i]) {
                ans++;
                st.top().second--;
                if(st.top().second == 0) {
                    st.pop();
                }
            }
        }
        return ans;
    }
};