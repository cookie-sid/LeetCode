class Solution {
public:
    
    static bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b) {
        if(a.first != b.first) {
            return a.first < b.first;
        }
        else {
            if(a.second.second * b.second.second < 0) {
                return a.second.second > b.second.second;
            }
            else {
                return a.second.first > b.second.first;
            }
        }
        return true;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0; i < buildings.size(); i++) {
            auto x = buildings[i];
            v.push_back({x[0],{x[2],(i+1)}});
            v.push_back({x[1],{x[2],-(i+1)}});
        }
        sort(v.begin(),v.end(),comp);
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        vector<vector<int>> ans;
        for(auto x : v) {
            // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
            if(x.second.second < 0) {
                x.second.second += 1;
                m[-x.second.second] = -1;
                while(!pq.empty() and (m[pq.top().second] == -1 or buildings[pq.top().second][1] <= x.first)) {
                    // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                    m[pq.top().second] = -1;
                    pq.pop();
                }
                if(pq.empty()) {
                    if(ans.back()[1] != 0) {
                        ans.push_back({x.first,0});
                    }
                }
                else {
                    if(ans.back()[1] > pq.top().first) {
                        ans.push_back({x.first,pq.top().first});
                    }
                }

            }
            else {
                x.second.second -= 1;
                pq.push({x.second.first,x.second.second});
                m[x.second.second] = 1;
                if(ans.size() == 0) {
                    ans.push_back({x.first,x.second.first});
                }
                else {
                    if(ans.back()[1] < x.second.first) {
                        ans.push_back({x.first,x.second.first});
                    }
                }
            }
        }
        return ans;
        
    }
};