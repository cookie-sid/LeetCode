class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        for(auto x : points) {
            double x_2 = x[0] * x[0];
            double y_2 = x[1] * x[1];
            double dist = sqrt(x_2 + y_2);
            pq.push(make_pair(dist,x));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};