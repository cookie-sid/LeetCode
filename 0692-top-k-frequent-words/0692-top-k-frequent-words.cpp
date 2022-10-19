class Solution {
public:
    
    struct CustomCompare
    {
        bool operator()(const pair<int,string>& lhs, const pair<int,string>& rhs)
        {
            if(lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x : words) {
            m[x] += 1;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>, CustomCompare> q;
        for(auto x : m) {
            q.push(make_pair(x.second,x.first));
            if(q.size() > k) {
                // cout<<q.top().first<<" "<<q.top().second<<endl;
                q.pop();
            }
        }
        vector<string> ans;
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};