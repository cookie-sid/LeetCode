class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        map<vector<string>,int> m;
        map<string,vector<pair<int,string>>> webs;
        
        for(int i = 0; i < username.size(); i++) {
            webs[username[i]].push_back(make_pair(timestamp[i],website[i]));
        }
        
        for(auto x : webs) {
            vector<pair<int,string>> currWebs = x.second;
            sort(currWebs.begin(),currWebs.end());
            
            map<vector<string>,bool> pp;
            
            if(currWebs.size() >= 3) {
                for(int j = 0; j < currWebs.size() - 2; j++) {
                    for(int k = j + 1; k < currWebs.size() - 1; k++) {
                        for(int l = k + 1; l < currWebs.size(); l++) {
                            pp[{currWebs[j].second,currWebs[k].second,currWebs[l].second}] = true;
                        }
                    }
                }
            }
            for(auto p : pp) {
                m[p.first] += 1;
            }
            // for(auto x : m) {
            //     for(auto y: x.first) {
            //         cout<<y<<" ";
            //     }
            //     cout<<x.second<<endl;
            // }
            // cout<<endl;
        }
        
        int maxi = -1;
        vector<string> ans;
        for(auto x : m) {
            if(x.second > maxi) {
                maxi = x.second;
            }
        }
        vector<vector<string>> temp;
        for(auto x : m) {
            if(x.second == maxi) {
                temp.push_back(x.first);
            }
        }
        
        sort(temp.begin(),temp.end());
        
        return temp[0];
    }
};