class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        unordered_map<int,int> m;
        vector<pair<pair<int,int>,int>> ordered;
        for(int i = 0; i < startTime.size(); i++) {
            ordered.push_back(make_pair(make_pair(endTime[i],startTime[i]),profit[i]));
        }
        
        sort(ordered.begin(),ordered.end());
        
        int start = 0;
        for(auto x : ordered) {
            // cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
            startTime[start] = x.first.second;
            endTime[start] = x.first.first;
            profit[start] = x.second;
            start++;
        }
        
        m[endTime[0]] = profit[0];
        int maxi = -1;
        
        for(int i = 1; i < startTime.size(); i++) {
            if(startTime[i] >= endTime[i-1]) {
                m[endTime[i]] = m[endTime[i-1]] + profit[i];
            }
            else {
                int temp = upper_bound(endTime.begin(),endTime.end(),startTime[i]) - endTime.begin();

                if(temp  == 0) {
                    m[endTime[i]] = max(m[endTime[i-1]],profit[i]);
                }
                else {
                    m[endTime[i]] = max(m[endTime[i-1]],m[endTime[temp-1]] + profit[i]);
                }
            }
            maxi = max(maxi,m[endTime[i]]);
        }
        
        return maxi;
        
    }
};